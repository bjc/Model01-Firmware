// -*- mode: c++ -*-

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-NumPad.h>
#include <Kaleidoscope-HardwareTestMode.h>
#include <Kaleidoscope-HostPowerManagement.h>
#include <Kaleidoscope-MagicCombo.h>
#include <Kaleidoscope-Qukeys.h>
#include <Kaleidoscope-USB-Quirks.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-EEPROM-Keymap.h>
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope-Syster.h>
#include <Kaleidoscope-Unicode.h>
#include <Kaleidoscope-LEDEffect-BootGreeting.h>
#include <Kaleidoscope-LEDEffect-Breathe.h>
#include <Kaleidoscope-IdleLEDs.h>
#include <Kaleidoscope-LayerHighlighter.h>
#include <Kaleidoscope-SpaceCadet.h>
#include <Kaleidoscope-Heatmap.h>

enum { MACRO_VERSION_INFO,
       MACRO_ANY,
       WOW,
       SAUCY,
       LUL,
       ZZZ,
       GIVE_PLZ,
       TAKE_NRG,
       SEEMS_GOOD,
       GASM
     };

enum { PRIMARY, FUNCTION, NUMPAD, EMOTES }; // layers

typedef struct {
  uint8_t index;
  const char *string;
} emote;

const char wow[] PROGMEM = "eeriedWow";
const char saucy[] PROGMEM = "eeriedSaucy";
const char lul[] PROGMEM = "supert25LUL";
const char zzz[] PROGMEM = "plasmoWife";
const char givePLZ[] PROGMEM = "GivePLZ";
const char takeNRG[] PROGMEM = "TakeNRG";
const char seemsGood[] PROGMEM = "SeemsGood";
const char gasm[] PROGMEM = "kdubGasm";

static const emote emotes[] = {
  { WOW, wow },
  { SAUCY, saucy },
  { LUL, lul },
  { ZZZ, zzz },
  { GIVE_PLZ, givePLZ },
  { TAKE_NRG, takeNRG },
  { SEEMS_GOOD, seemsGood },
  { GASM, gasm },
  { 255, NULL }
};

// *INDENT-OFF*

KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED
  (Key_Escape,      Key_1,         Key_2,       Key_3,      Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick,    Key_Quote,     Key_Comma,   Key_Period, Key_P, Key_Y, Key_Tab,
   Key_PageUp,      Key_A,         Key_O,       Key_E,      Key_U, Key_I,
   Key_PageDown,    Key_Semicolon, Key_Q,       Key_J,      Key_K, Key_X, Key_LeftGui,
   Key_LeftBracket, Key_Backspace, LSHIFT(Key_LeftBracket), LSHIFT(Key_9),
   //Key_LeftControl, Key_Backspace, Key_LeftAlt, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   LockLayer(EMOTES), Key_6, Key_7, Key_8, Key_9, Key_0, LockLayer(NUMPAD),
   Key_Enter,         Key_F, Key_G, Key_C, Key_R, Key_L, Key_Slash,
                      Key_D, Key_H, Key_T, Key_N, Key_S, Key_Minus,
   SYSTER,            Key_B, Key_M, Key_W, Key_V, Key_Z, Key_Equals,
   LSHIFT(Key_0), LSHIFT(Key_RightBracket), Key_Spacebar, Key_RightBracket,
   //Key_RightShift, Key_RightAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

  [FUNCTION] = KEYMAP_STACKED
  (___,       Key_F1,           Key_F2,        Key_F3,        Key_F4,                     Key_F5,                  Key_CapsLock,
   Key_Tab,   ___,              Key_PageUp,    Key_UpArrow,   Key_PageDown,               Key_Home,                ___,
   Key_Copy,  ___,              Key_LeftArrow, Key_DownArrow, Key_RightArrow,             Key_End,
   Key_Paste, Key_PrintScreen,  Key_Insert,    ___,           Consumer_ScanPreviousTrack, Consumer_PlaySlashPause, Consumer_ScanNextTrack,
   ___, Key_Delete, ___, ___,
   ___,

   ___,               Key_F6,        Key_F7,                   Key_F8,          Key_F9,         Key_F10,       Key_F11,
   Key_ScrollLock,    Key_Home,      Key_PageUp,               Key_UpArrow,     Key_PageDown,   ___,           Key_F12,
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

   M(MACRO_VERSION_INFO),  ___, Key_7, Key_8,      Key_9,              Key_KeypadSubtract, ___,
   ___,                    ___, Key_4, Key_5,      Key_6,              Key_KeypadAdd,      ___,
                           ___, Key_1, Key_2,      Key_3,              Key_Equals,         ___,
   ___,                    ___, Key_0, Key_Period, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___),

  [EMOTES] =  KEYMAP_STACKED
  (___, ___,    ___, ___,     ___, ___, ___,
   ___, ___,    ___, ___,     ___, ___, ___,
   ___, ___,    ___, ___,     ___, M(SEEMS_GOOD),
   ___, M(ZZZ), ___, M(GASM), ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   ___, ___, ___, ___,         ___,         ___,      ___,
   ___, ___, ___, ___,         ___,         M(WOW),   ___,
        ___, ___, ___,         M(LUL),      M(SAUCY), ___,
   ___, ___, ___, M(GIVE_PLZ), M(TAKE_NRG), ___,      ___,
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
    Unicode.type(0x2615);
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
  bool toggledOn = false;
  if (keyToggledOn(keyState)) {
    lastKey.setKeyCode(Key_A.getKeyCode() + (uint8_t)(millis() % 36));
    toggledOn = true;
  }

  if (keyIsPressed(keyState))
    Kaleidoscope.hid().keyboard().pressKey(lastKey, toggledOn);
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
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.disable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.enable();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
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
  COMBO_TOGGLE_NKRO_MODE,
  // Enter test mode
  COMBO_ENTER_TEST_MODE
};

/** Wrappers, to be used by MagicCombo. **/

/**
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/**
 *  This enters the hardware test mode
 */
static void enterHardwareTestMode(uint8_t combo_index) {
  HardwareTestMode.runTests();
}


/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = { R3C6, R2C6, R3C7 }},
                 {.action = enterHardwareTestMode,
                  // Left Fn + Prog + LED
                  .keys = { R3C6, R0C0, R0C6 }});

static LayerHighlighter emoteHighlighter(EMOTES);

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(EEPROMSettings,
                          //HostOS,
                          Unicode,
                          Qukeys,
                          //SpaceCadet,
                          //MacrosOnTheFly,
                          Syster,
                          // LEDControl provides support for other LED
                          // modes
                          LEDControl,
                          IdleLEDs,
                          BootGreetingEffect,
                          LEDBreatheEffect,
                          HeatmapEffect,

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
                          //HostPowerManagement,

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

  // Necessary for FreeBSD, as it doesn't support NKRO.
  BootKeyboard.default_protocol = HID_BOOT_PROTOCOL;

  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumPad.numPadLayer = NUMPAD;

  emoteHighlighter.lockHue = 100;
  emoteHighlighter.color = CRGB(255, 255, 0);
  LEDBreatheEffect.hue = 212;

  QUKEYS(kaleidoscope::plugin::Qukey(0, KeyAddr(3, 7), Key_LeftShift),
         kaleidoscope::plugin::Qukey(0, KeyAddr(3, 8), Key_RightShift),
         kaleidoscope::plugin::Qukey(0, KeyAddr(0, 7), Key_LeftControl),
         kaleidoscope::plugin::Qukey(0, KeyAddr(0, 8), Key_RightControl),
         kaleidoscope::plugin::Qukey(0, KeyAddr(2, 7), Key_LeftAlt),
         kaleidoscope::plugin::Qukey(0, KeyAddr(2, 8), Key_RightAlt),
         kaleidoscope::plugin::Qukey(0, KeyAddr(2, 9), Key_RightGui));
  Qukeys.setOverlapThreshold(25);

  IdleLEDs.setIdleTimeoutSeconds(300);
}

void loop() {
  Kaleidoscope.loop();
}

void systerAction(kaleidoscope::plugin::Syster::action_t action, const char *symbol) {
  switch (action) {
  case kaleidoscope::plugin::Syster::StartAction:
    Unicode.type(0x2328);
    break;

  case kaleidoscope::plugin::Syster::EndAction:
    handleKeyswitchEvent(Key_Backspace, UnknownKeyswitchLocation, IS_PRESSED | INJECTED);
    Kaleidoscope.hid().keyboard().sendReport();
    handleKeyswitchEvent(Key_Backspace, UnknownKeyswitchLocation, WAS_PRESSED | INJECTED);
    Kaleidoscope.hid().keyboard().sendReport();
    break;

  case kaleidoscope::plugin::Syster::SymbolAction:
    Serial.print("systerAction = ");
    Serial.println(symbol);
    if (strcmp(symbol, "coffee") == 0) {
      Unicode.type(0x2615);
    } else if (strcmp(symbol, "=/") == 0) { // =/
      Unicode.type(0x1f615);
    } else if (strcmp(symbol, "=9") == 0) { // =(
      Unicode.type(0x1f641);
    } else if (strcmp(symbol, "=:") == 0) { // =)
      Unicode.type(0x1f642);
    } else if (strcmp(symbol, "9=") == 0) { // (=
      Unicode.type(0x1f643);
    } else if (strcmp(symbol, "=p") == 0) { // =P
      Unicode.type(0x1f61b);
    } else if (strcmp(symbol, "=x") == 0) { // =x
      Unicode.type(0x1f636);
    } else if (strcmp(symbol, "b:") == 0) { // B)
      Unicode.type(0x1f60e);
    } else if (strcmp(symbol, ";:") == 0) { // ;)
      Unicode.type(0x1f609);
    } else if (strcmp(symbol, "1::") == 0) { // 100
      Unicode.type(0x1f4af);
    } else if (strcmp(symbol, "eye") == 0) {
      Unicode.type(0x1f440);


    } else if (strcmp(symbol, "heye") == 0) {
      Unicode.type(0x1f60d);
    } else if (strcmp(symbol, "think") == 0) {
      Unicode.type(0x1f914);
    } else if (strcmp(symbol, "party") == 0) {
      Unicode.type(0x1f389);
    } else if (strcmp(symbol, "flex") == 0) {
      Unicode.type(0x1f4aa);
    } else if (strcmp(symbol, "pray") == 0) {
      Unicode.type(0x1f64f);
    } else if (strcmp(symbol, "kiss") == 0) {
      Unicode.type(0x1f618);
    } else if (strcmp(symbol, "rip") == 0) {
      Unicode.type(0x26b0);
    } else if (strcmp(symbol, "dead") == 0) {
      Unicode.type(0x1f480);
    } else if (strcmp(symbol, "ok") == 0) {
      Unicode.type(0x1f58f);
    } else if (strcmp(symbol, "yes") == 0) {
      Unicode.type(0x1f592);
    } else if (strcmp(symbol, "no") == 0) {
      Unicode.type(0x1f593);
    } else if (strcmp(symbol, "fu") == 0) {
      Unicode.type(0x1f595);
    } else if (strcmp(symbol, "spy") == 0) {
      Unicode.type(0x1f575);
    } else if (strcmp(symbol, "ooo") == 0) {
      Unicode.type(0x1f47b);
    }
    break;
  }
}
