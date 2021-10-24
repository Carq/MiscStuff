#NoTrayIcon
#SingleInstance force

; A new instance is made every time the skin is reset or a setting is changed
; %1% = Rainmeter path, %2% = #@#vars.inc path
if %0% = 0
{
    Msgbox Don't manually run this. Refresh the skin to run automatically. This won't run if auto-switch is disabled.
	ExitApp
}

; Get variables from #@#vars.inc
FileRead, text, %2%

IfInString, text, autoSwitch=1
    autoswitch := 1
IfInString, text, autoSwitch=0
    autoswitch := 0
IfInString, text, hideSkins=0
    hideskins := 0
IfInString, text, hideSkins=1
    hideskins := 1
IfInString, text, hideSkins=2
    hideskins := 2
IfInString, text, executedOnce=0
    executedonce := 0
IfInString, text, executedOnce=1
    executedonce := 1

; Close the ahk if autoswitch is off
if not autoswitch or not executedonce
    exitapp

; Initial setup
knownhiddentaskbar := 0
WinGetPos, , y, , , ahk_class Shell_TrayWnd
WinGetPos, , , w, h, A
WinGetClass, class, A

if isfullscreen()
    insidefullscreen()
else
    outsidefullscreen()


Loop {
    Sleep, 250

    ; Shoutouts to WinExist() for deleting 2 hours of my life, when trying to
    ; troublehsoot why my skin was just not working at certain points
    Process, Exist, Rainmeter.exe
    if not ErrorLevel
        exitapp

    WinGetPos, , y, , , ahk_class Shell_TrayWnd
    WinGetPos, , , w, h, A
    WinGetClass, class, A

    checkdebug()

    if not fullscreenvalue and isfullscreen()
        insidefullscreen()
    else if fullscreenvalue and not isfullscreen() and not (class = "RainmeterMeterWindow" and not knownhiddentaskbar)
        outsidefullscreen()
}


isfullscreen() {
    global y, w, h, class

    ; 'and y' because no value for whatever reason is considered below 0
    taskbarhidden := (y >= (A_ScreenHeight - 20)) or ((y < 0) and y)
    fullscreenapp := (w >= A_ScreenWidth) and (h >= A_ScreenHeight)

    ; knownhiddentaskbar lets me know the monitor should be in taskbar mode
    ; when hovering over the taskbar and having a maximized app focused
    if taskbarhidden
        global knownhiddentaskbar
        knownhiddentaskbar := 1

    ; These 2 specific OS programs use the entire screen and should be ignored
    ; Btw, can't mix both these ifs for whatever reason
    if class in WorkerW,Progman
    {
        if not taskbarhidden
            return False
    }

    return taskbarhidden or (not knownhiddentaskbar and fullscreenapp)
}

insidefullscreen() {
    global fullscreenvalue, hideskins, 1
    fullscreenvalue := 1

    if hideskins = 1
        Run %1% [!Hide GerosMonitor\Portable][!Hide GerosMonitor\Taskbar]
    else
        Run %1% [!Show GerosMonitor\Portable][!Hide GerosMonitor\Taskbar]
}

outsidefullscreen() {
    global fullscreenvalue, hideskins, 1
    fullscreenvalue := 0

    if hideskins = 2
        Run %1% [!Hide GerosMonitor\Portable][!Hide GerosMonitor\Taskbar]
    else
        Run %1% [!Hide GerosMonitor\Portable][!Show GerosMonitor\Taskbar]
}

checkdebug() {
    Loop 4 {
        if not ((GetKeyState("Ctrl")) and (GetKeyState("Shift")) and (GetKeyState("Alt")) and (GetKeyState(",")))
            return

        Sleep 200
    }

    global y, w, h, class
    Msgbox Debug message from holding Ctrl+Shift+Alt+Comma.`n %A_ScreenWidth%x%A_ScreenHeight% Screen `n %y%px Shell_TrayWnd (taskbar) `n %w%x%h% %class%
}
