#ifndef MEDIA_h
#define MEDIA_h

#include <HID.h>

#if !defined(_USING_HID)

#warning "Using legacy HID core (non pluggable)"

#else

//================================================================================
//================================================================================
//  Media

#define MEDIA_CLEAR 0
#define MEDIA_VOL_UP 1
#define MEDIA_VOL_DOWN 2
#define MEDIA_MUTE 4
#define MEDIA_PLAY 8
#define MEDIA_PAUSE 16
#define MEDIA_STOP 32
#define MEDIA_NEXT 64
#define MEDIA_PREV 128
#define MEDIA_FFD 256
#define MEDIA_RWD 512

class Media_
{
private:
  void sendReport(uint8_t id, const void* data, int len);

public:
  Media_(void);

  // accepts MEDIA_* constants
  void send(uint16_t cmd);

  // Volume
  void increase(void);
  void decrease(void);
  void mute(void);

  // Playback
  void play(void);
  void pause(void);
  void stop(void);

  // Track Controls
  void next(void);
  void previous(void);
  void forward(void);
  void rewind(void);

  // Send an empty report to prevent repeated actions
  void clear(void);
};
extern Media_ Media;

#endif
#endif
