#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.
FileEncoding, UTF-8-RAW

usePY(type)
{
FileDelete, temp.txt
FileAppend, %clipboard%, temp.txt
ToolTip, %clipboard%
;ToolTip ,"%A_ScriptDir%/HistoryCleaner.py"
RunWait, py "%A_ScriptDir%/HistoryCleaner.py"
Sleep, 1000
ToolTip ,
; Sleep ,1000
; FileRead, Clipboard, *c temp.txt
}
#Persistent
OnClipboardChange("ClipChanged")
return

ClipChanged(Type) {
    Sleep, 50
    if(not MyChange)
    {
        ToolTip %clipboard%
        FileDelete, temp.txt
        FileAppend, %clipboard%, temp.txt
        RunWait, py %A_ScriptDir%/HistoryCleaner.py
        Sleep 1000
        ToolTip  ; 关闭提示.
        MyChange := true
        FileRead, Clipboard, temp.txt
        FileDelete, temp.txt
    }
    Else
    {
        MyChange := False
    }
    return 
}