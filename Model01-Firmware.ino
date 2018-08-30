#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-NumPad.h>
#include <LED-Off.h>
#include <Kaleidoscope-Model01-TestMode.h>
#include <Kaleidoscope-HostPowerManagement.h>
#include <Kaleidoscope-MagicCombo.h>
#include <Kaleidoscope-USB-Quirks.h>

#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope/HostOS-select.h>
#include <Kaleidoscope-Syster.h>
#include <Kaleidoscope-Unicode.h>
#include <kaleidoscope/hid.h>
#include <Kaleidoscope-Qukeys.h>
#include <Kaleidoscope-MacrosOnTheFly.h>
#include <Kaleidoscope-LEDEffect-DigitalRain.h>
#include <Kaleidoscope-LED-Wavepool.h>
#include <Kaleidoscope-LayerHighlighter.h>

enum { MACRO_VERSION_INFO,
       MACRO_ANY,
       POG_CHAMP,
       LUL,
       ZZZ,
       GIVE_PLZ,
       TAKE_NRG,
       SEEMS_GOOD
     };

enum { PRIMARY, FUNCTION, NUMPAD, EMOTES }; // layers

typedef struct {
  uint8_t index;
  const char *string;
} emote;

const char pogChamp[] PROGMEM = "PogChamp";
const char lul[] PROGMEM = "supert25LUL";
const char zzz[] PROGMEM = "plasmoWife";
const char givePLZ[] PROGMEM = "GivePLZ";
const char takeNRG[] PROGMEM = "TakeNRG";
const char seemsGood[] PROGMEM = "SeemsGood";

static const emote emotes[] = {
  { POG_CHAMP, pogChamp },
  { LUL, lul },
  { ZZZ, zzz },
  { GIVE_PLZ, givePLZ },
  { TAKE_NRG, takeNRG },
  { SEEMS_GOOD, seemsGood },
  { 255, NULL }
};

// *INDENT-OFF*

KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED
  (Key_Escape,      Key_1,         Key_2,       Key_3,      Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick,    Key_Quote,     Key_Comma,   Key_Period, Key_P, Key_Y, Key_Tab,
   Key_MacroRec,    Key_A,         Key_O,       Key_E,      Key_U, Key_I,
   Key_MacroPlay,   Key_Semicolon, Key_Q,       Key_J,      Key_K, Key_X, Key_LeftGui,
   Key_LeftBracket, Key_Backspace, LSHIFT(Key_LeftBracket), LSHIFT(Key_9),
   ShiftToLayer(FUNCTION),

   LockLayer(EMOTES), Key_6, Key_7, Key_8, Key_9, Key_0, LockLayer(NUMPAD),
   Key_Enter,         Key_F, Key_G, Key_C, Key_R, Key_L, Key_Slash,
                      Key_D, Key_H, Key_T, Key_N, Key_S, Key_Minus,
   SYSTER,            Key_B, Key_M, Key_W, Key_V, Key_Z, Key_Equals,
   LSHIFT(Key_0), LSHIFT(Key_RightBracket), Key_Spacebar, Key_RightBracket,
   ShiftToLayer(FUNCTION)),

  [FUNCTION] = KEYMAP_STACKED
  (___,       Key_F1,           Key_F2,        Key_F3,        Key_F4,                     Key_F5,                  Key_CapsLock,
   Key_Tab,   ___,              Key_PageUp,    Key_UpArrow,   Key_PageDown,               Key_Home,                ___,
   Key_Copy,  ___,              Key_LeftArrow, Key_DownArrow, Key_RightArrow,             Key_End,
   Key_Paste, Key_PrintScreen,  Key_Insert,    ___,           Consumer_ScanPreviousTrack, Consumer_PlaySlashPause, Consumer_ScanNextTrack,
   ___, Key_Delete, ___, ___,
   ___,

   ___,               Key_F6,        Key_F7,                   Key_F8,          Key_F9,         Key_F10,       Key_F11,
   ___,               Key_Home,      Key_PageUp,               Key_UpArrow,     Key_PageDown,   ___,           Key_F12,
                      Key_End,       Key_LeftArrow,            Key_DownArrow,   Key_RightArrow, ___,           ___,
   Key_PcApplication, Consumer_Mute, Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,   Key_Backslash, Key_Pipe,
   ___, ___, Key_Enter, ___,
   ___),

  [NUMPAD] = KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   M(MACRO_VERSION_INFO),  ___, Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadSubtract, ___,
   ___,                    ___, Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadAdd,      ___,
                           ___, Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,         ___,
   ___,                    ___, Key_Keypad0, Key_KeypadDot, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___),

  [EMOTES] =  KEYMAP_STACKED
  (___, ___,    ___, ___, ___, ___, ___,
   ___, ___,    ___, ___, ___, ___, ___,
   ___, ___,    ___, ___, ___, M(SEEMS_GOOD),
   ___, M(ZZZ), ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   ___, ___, ___, ___,         ___,         ___,          ___,
   ___, ___, ___, ___,         ___,         M(POG_CHAMP), ___,
        ___, ___, ___,         M(LUL),      ___,          ___,
   ___, ___, ___, M(GIVE_PLZ), M(TAKE_NRG), ___,          ___,
   ___, ___, ___, ___,
   ___)
)

// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

static void anyKeyMacro(uint8_t keyState) {
  static Key lastKey;
  if (keyToggledOn(keyState))
    lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);

  if (keyIsPressed(keyState))
    kaleidoscope::hid::pressKey(lastKey);
}

const macro_t *emoteMacro(uint8_t macroIndex, uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    for (int i = 0; emotes[i].index != 255; i++) {
      if (emotes[i].index == macroIndex) {
        Macros.type(emotes[i].string);
        return MACRO_NONE;
      }
    }
  }
  return MACRO_NONE;
}

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;

  case MACRO_ANY:
    anyKeyMacro(keyState);
    break;

  default:
    emoteMacro(macroIndex, keyState);
  }

  return MACRO_NONE;
}

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::HostPowerManagement::Suspend:
    LEDControl.paused = true;
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    break;
  case kaleidoscope::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** This 'enum' is a list of all the magic combos used by the Model 01's
 * firmware The names aren't particularly important. What is important is that
 * each is unique.
 *
 * These are the names of your magic combos. They will be used by the
 * `USE_MAGIC_COMBOS` call below.
 */
enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE
};

/** A tiny wrapper, to be used by MagicCombo.
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = { R3C6, R2C6, R3C7 }
                 });

LayerHighlighter emoteHighlighter(EMOTES);

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(HostOS,
                          Unicode,
                          Qukeys,
                          MacrosOnTheFly,
                          Syster,
                          // LEDControl provides support for other LED
                          // modes
                          LEDControl,
                          WavepoolEffect,
                          LEDDigitalRainEffect,

                          // The numpad plugin is responsible for
                          // lighting up the 'numpad' mode with a
                          // custom LED effect
                          NumPad,
                          emoteHighlighter,

                          // The macros plugin adds support for macros
                          Macros,

                          // The HostPowerManagement plugin allows us
                          // to turn LEDs off when then host goes to
                          // sleep, and resume them when it wakes up.
                          HostPowerManagement,

                          // The MagicCombo plugin lets you use key
                          // combinations to trigger custom actions -
                          // a bit like Macros, but triggered by
                          // pressing multiple keys at the same time.
                          MagicCombo,

                          // The USBQuirks plugin lets you do some
                          // things with USB that we aren't
                          // comfortable - or able - to do
                          // automatically, but can be useful
                          // nevertheless. Such as toggling the key
                          // report protocol between Boot (used by
                          // BIOSes) and Report (NKRO).
                          USBQuirks);

void setup() {
  Serial.begin(9600);

  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumPad.numPadLayer = NUMPAD;

  emoteHighlighter.lockHue = 100;
  emoteHighlighter.color = CRGB(255, 255, 0);

  QUKEYS(kaleidoscope::Qukey(0, 3, 7, Key_LeftShift),
         kaleidoscope::Qukey(0, 3, 8, Key_RightShift),
         kaleidoscope::Qukey(0, 0, 7, Key_LeftControl),
         kaleidoscope::Qukey(0, 0, 8, Key_RightControl),
         kaleidoscope::Qukey(0, 2, 7, Key_LeftAlt),
         kaleidoscope::Qukey(0, 2, 8, Key_RightAlt),
         kaleidoscope::Qukey(0, 2, 9, Key_RightGui));
  Qukeys.setTimeout(200);
  Qukeys.setReleaseDelay(20);
}

void loop() {
  Kaleidoscope.loop();
}
