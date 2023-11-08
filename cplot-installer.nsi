!include "MUI2.nsh"

Name "CPlot 0.1.0"
Outfile "CPlot-0.1.0_Installer.exe"
!define MUI_ICON ".\assets\icons\cplot.ico"
!define MUI_FINISHPAGE_RUN "$INSTDIR\bin\CPlot.exe"

InstallDir $PROGRAMFILES64\CPlot

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE ".\LICENSE.txt" ; Use the correct file path
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

Var LaunchAppCheckbox

Section

    SetOutPath $INSTDIR
    CreateDirectory "$INSTDIR\bin"
    CreateDirectory "$INSTDIR\assets"
    CreateDirectory "$INSTDIR\assets\fonts"
    CreateDirectory "$INSTDIR\assets\icons"
    File ".\LICENSE.txt"
    SetOutPath $INSTDIR\bin
    File ".\Release\CPlot.exe"
    SetOutPath $INSTDIR\assets\fonts
    File ".\assets\fonts\calibri.ttf"
    SetOutPath $INSTDIR\assets\icons
    File ".\assets\icons\cplot.ico"

    WriteUninstaller "$INSTDIR\uninstallCPlot.exe"

SectionEnd

Section "Uninstall"
    Delete $INSTDIR\bin\CPlot.exe
    Delete $INSTDIR\bin\SDL2.dll
    RMDir $INSTDIR\bin
    Delete $INSTDIR\assets\fonts\calibri.ttf
    Delete $INSTDIR\assets\icons\cplot.ico
    Delete $INSTDIR\assets\icons\imgui.ini
    RMDir $INSTDIR\assets\fonts
    RMDir $INSTDIR\assets\icons
    RMDir $INSTDIR\assets
    Delete $INSTDIR\LICENSE.txt
    Delete $INSTDIR\uninstallCPlot.exe
    RMDir $INSTDIR
SectionEnd



Function .onInit
    StrCpy $LaunchAppCheckbox ${BST_CHECKED}
FunctionEnd


!insertmacro MUI_LANGUAGE "English"
