#ifndef _TCONTROLLER_H_
#define _TCONTROLLER_H_ 1

#include <termios.h>
#include <unistd.h>

class TController {
public:
  enum mode { MODE_DEFAULT, MODE_RAW };

  TController() {
    // store terminal default and custom states
    tcgetattr(STDIN_FILENO, &termStd);
    termRaw = termStd;
    termRaw.c_lflag &= ~(ICANON/* | ECHO*/);
  }

  void setMode(mode newMode) {
    switch (newMode) {
      case MODE_DEFAULT:
        tcsetattr(STDIN_FILENO, TCSANOW, &termStd);
        break;
      case MODE_RAW:
        tcsetattr(STDIN_FILENO, TCSANOW, &termRaw);
        break;
    }
  }
private:
  // terminal state structures
  struct termios termStd, termRaw;
};

#endif /* _TCONTROLLER_H_ */
