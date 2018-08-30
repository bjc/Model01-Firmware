#include <Kaleidoscope-Syster.h>
#include <Kaleidoscope-Unicode.h>

void systerAction(kaleidoscope::Syster::action_t action, const char *symbol) {
  switch (action) {
  case kaleidoscope::Syster::StartAction:
    Unicode.type(0x2328);
    break;

  case kaleidoscope::Syster::EndAction:
    handleKeyswitchEvent(Key_Backspace, UNKNOWN_KEYSWITCH_LOCATION, IS_PRESSED | INJECTED);
    kaleidoscope::hid::sendKeyboardReport();
    handleKeyswitchEvent(Key_Backspace, UNKNOWN_KEYSWITCH_LOCATION, WAS_PRESSED | INJECTED);
    kaleidoscope::hid::sendKeyboardReport();
    break;

  case kaleidoscope::Syster::SymbolAction:
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
    }
    break;
  }
}

const char keyToChar(Key key) {
  switch (key.keyCode) {
  case Key_A.keyCode ... Key_Z.keyCode:
    return 'a' + (key.keyCode - Key_A.keyCode);
  case Key_1.keyCode ... Key_0.keyCode:
    return '1' + (key.keyCode - Key_1.keyCode);
  case Key_Minus.keyCode:
    return '-';
  case Key_Equals.keyCode:
    return '=';
  case Key_LeftBracket.keyCode:
    return '[';
  case Key_RightBracket.keyCode:
    return ']';
  case Key_Backslash.keyCode:
    return '\\';
  case Key_Semicolon.keyCode:
    return ';';
  case Key_Quote.keyCode:
    return '\'';
  case Key_Backtick.keyCode:
    return '`';
  case Key_KeypadLeftParen.keyCode:
    return '(';
  case Key_KeypadRightParen.keyCode:
    return ')';
  case Key_Slash.keyCode:
    return '/';
  }

  return 0;
}
