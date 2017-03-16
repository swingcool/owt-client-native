/*
 * Intel License
 */

#ifndef WOOGEEN_BASE_CUSTOMIZEDVIDEODECODERPROXY_H_
#define WOOGEEN_BASE_CUSTOMIZEDVIDEODECODERPROXY_H_

#include <vector>

#include "webrtc/modules/video_coding/include/video_codec_interface.h"
#include "webrtc/system_wrappers/include/clock.h"
#include "talk/woogeen/sdk/include/cpp/woogeen/base/videodecoderinterface.h"

namespace woogeen {
namespace base {

using namespace webrtc;

class CustomizedVideoDecoderProxy : public VideoDecoder {
 public:
  CustomizedVideoDecoderProxy(VideoCodecType type, VideoDecoderInterface* external_video_decoder);
  virtual ~CustomizedVideoDecoderProxy();

  int32_t InitDecode(const VideoCodec* codec_settings,
                     int32_t number_of_cores) override;

  int32_t Decode(const EncodedImage& input,
                 bool missing_frames,
                 const RTPFragmentationHeader* fragmentation,
                 const CodecSpecificInfo* codec_specific_info,
                 int64_t render_time_ms) override;

  int32_t RegisterDecodeCompleteCallback(
      DecodedImageCallback* callback) override;

  int32_t Release() override;

  const char* ImplementationName() const override;

 private:
  VideoCodec codec_settings_;
  VideoCodecType codec_type_;
  DecodedImageCallback* decoded_image_callback_;
  VideoDecoderInterface* external_decoder_;
};

}
}

#endif  // WOOGEEN_BASE_CUSTOMIZEDVIDEODECODERPROXY_H_