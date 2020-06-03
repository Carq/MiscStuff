cd "C:\Users\Carq\AppData\Local\slack\"
start slack.exe

cd "C:\Program Files (x86)\Microsoft\Skype for Desktop\"
start Skype.exe

cd "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\OpenVPN"
start "" "OpenVPN GUI.lnk"

cd "C:\Program Files\ConEmu"
ConEmu64.exe -runlist -new_console:d:C:\Users\xxx\Projects\xxx\backend\ "C:\Program Files\Git\bin\sh.exe" -l -i ^|^|^| -new_console:d:C:\Users\xxx\Projects\xxx\frontend\ "C:\Program Files\Git\bin\sh.exe" -l -i -new_console:s50H ^|^|^| -new_console:d:CC:\Users\xxx\Projects\xxx\frontend\ "C:\Program Files\Git\bin\sh.exe" -l -i -new_console:s50V
