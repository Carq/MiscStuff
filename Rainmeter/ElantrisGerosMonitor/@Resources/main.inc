[Rainmeter]
AccurateText = 1
Update = 50
DefaultUpdateDivider = 20
ContextTitle2 = Introduction/Help
ContextAction2 = [!ActivateConfig GerosMonitor\Help]
ContextTitle3 = Settings
ContextAction3 = [!ActivateConfig GerosMonitor\Settings]
ContextTitle4 = Restart
ContextAction4 = [!RefreshGroup Monitors]
ContextTitle5 = Manage Rainmeter
ContextAction5 = [!Manage Skins GerosMonitor]
ContextTitle6 = Unload
ContextAction6 = [taskkill /f /im "GerosMonitor - FullscreenDetector.exe"][!DeactivateConfigGroup Monitors]

[Variables]
@Include=vars.inc


; Styles (text, graph, rect, graphEX, rectEX) and coords (down, right, same)
[styleText]
FontFace = Roboto
FontSize = 8
FontColor = #colorTxt#
StringAlign = left
AntiAlias = 1
w = 45
h = 8

[styleTextEx]
FontFace = Roboto
FontSize = 8
FontColor = #colorTxt#
StringAlign = left
AntiAlias = 1
w = 100
h = 8

[styleRect]
ImageName = #@#Images\rect30EX.png

[styleRectEX]
ImageName = #@#Images\rectEX.png
Hidden = 1

[styleGraph]
w = 31
h = 11

[styleGraphEX]
w = 51
h = 11
Hidden = 1

[coordDown]
x = r
y = 17r

[coordDownLeft]
x = -10r
y = 17r

[coordDownRight]
x = 5r
y = 17r

[coordRight]
x = 69r
y = -17r

[coordSame]
x = r
y = r



; Measures (CPU, CPUtemp, GPU, GPUtemp, RAM, DL, UP, FPS)
[MeasureCPU]
Measure = CPU

[MeasureCPUtemp]
Measure = Plugin
Plugin = MSIAfterburner.dll
DataSource = CPU temperature
MinValue = 0
MaxValue = ((#fahrenheit# = 1) ? 212 : 100)
IfCondition = MeasureCPUtemp >= #tempHot#
IfTrueAction = [!SetOption MeterCPUtemp FontColor #colorHot#][!SetOption MeterCPUtempGraph SolidColor #colorHot#64][!SetOption MeterCPUtempGraphEX SolidColor #colorHot#64]
IfFalseAction = [!SetOption MeterCPUtemp FontColor #colorTxt#][!SetOption MeterCPUtempGraph SolidColor #colorNUL#][!SetOption MeterCPUtempGraphEX SolidColor #colorNUL#]
IfCondition2 = MeasureCPUtemp = 0
IfTrueAction2 = [!SetOption MeterCPUtemp FontColor #colorTxt#32][!SetOption MeterCPUtempGraph PrimaryColor #colorCPU#32][!SetOption MeterCPUtempGraphEX PrimaryColor #colorCPU#32][!SetOption MeterCPUtempRect ImageTint #colorCPU#32][!SetOption MeterCPUtempRectEX ImageTint #colorCPU#32]
IfFalseAction2 = [!SetOption MeterCPUtemp FontColor #colorTxt#][!SetOption MeterCPUtempGraph PrimaryColor #colorCPU#][!SetOption MeterCPUtempGraphEX PrimaryColor #colorCPU#][!SetOption MeterCPUtempRect ImageTint #colorCPU#][!SetOption MeterCPUtempRectEX ImageTint #colorCPU#]
IfCondition3 = MeasureCPUtemp >= 1000
IfTrueAction = [!SetOption MeasureCPUtemp Text ∞°C]
IfFalseAction = [!SetOption MeasureCPUtemp Text %1°C]

[MeasureGPU0temp]
Measure = Plugin
Plugin = MSIAfterburner.dll
DataSource = GPU temperature
MinValue = 0
MaxValue = ((#fahrenheit# = 1) ? 212 : 100)
IfConditionMode = 1
IfCondition = MeasureGPU0temp >= #tempHot#
IfTrueAction = [!SetOption MeterGPU0temp FontColor #colorHot#][!SetOption MeterGPU0tempGraph SolidColor #colorHot#64][!SetOption MeterGPU0tempGraphEX SolidColor #colorHot#64]
IfFalseAction = [!SetOption MeterGPU0temp FontColor #colorTxt#][!SetOption MeterGPU0tempGraph SolidColor #colorNUL#][!SetOption MeterGPU0tempGraphEX SolidColor #colorNUL#]
IfCondition2 = MeasureGPU0temp = 0
IfTrueAction2 = [!SetOption MeterGPU0temp FontColor #colorTxt#32][!SetOption MeterGPU0tempRect ImageTint #colorGPU#32][!SetOption MeterGPU0tempRectEX ImageTint #colorGPU#32][!SetOption MeterGPU0tempGraph PrimaryColor #colorGPU#32][!SetOption MeterGPU0tempGraphEX PrimaryColor #colorGPU#32]
IfFalseAction2 = [!SetOption MeterGPU0temp FontColor #colorTxt#][!SetOption MeterGPU0tempRect ImageTint #colorGPU#][!SetOption MeterGPU0tempRectEX ImageTint #colorGPU#][!SetOption MeterGPU0tempGraph PrimaryColor #colorGPU#][!SetOption MeterGPU0tempGraphEX PrimaryColor #colorGPU#]
IfCondition3 = MeasureGPU0temp >= 1000
IfTrueAction = [!SetOption MeasureGPU0temp Text ∞°C]
IfFalseAction = [!SetOption MeasureGPU0temp Text %1°C]

[MeasureGPU1temp]
Measure = Plugin
Plugin = MSIAfterburner.dll
DataSource = GPU1 temperature
MinValue = 0
MaxValue = ((#fahrenheit# = 1) ? 212 : 100)
IfCondition = MeasureGPU1temp >= #tempHot#
IfTrueAction = [!SetOption MeterGPU1temp FontColor #colorHot#][!SetOption MeterGPU1tempGraph SolidColor #colorHot#64][!SetOption MeterGPU1tempGraphEX SolidColor #colorHot#64]
IfFalseAction = [!SetOption MeterGPU1temp FontColor #colorTxt#][!SetOption MeterGPU1tempGraph SolidColor #colorNUL#][!SetOption MeterGPU1tempGraphEX SolidColor #colorNUL#]
IfCondition2 = MeasureGPU1temp = 0
IfTrueAction2 = [!ShowMeterGroup GPU0][!HideMeterGroup GPU1]
IfFalseAction2 = [!HideMeterGroup GPU0][!ShowMeterGroup GPU1]
IfCondition3 = MeasureGPU1temp >= 1000
IfTrueAction = [!SetOption MeasureGPU1temp Text ∞°#tempLetter#]
IfFalseAction = [!SetOption MeasureGPU1temp Text %1°#tempLetter#]

[MeasureGPU0]
Measure = Plugin
Plugin = MSIAfterburner.dll
DataSource = GPU usage
MinValue = 0
MaxValue = 100
IfCondition = (MeasureGPU0temp = 0) && (MeasureCPUtemp = 0)
IfTrueAction = [!SetOption MeterGPU0 FontColor #colorTxt#32][!SetOption MeterGPU0graph PrimaryColor #colorGPU#32][!SetOption MeterGPU0graphEX PrimaryColor #colorGPU#32][!SetOption MeterGPU0rect ImageTint #colorGPU#32][!SetOption MeterGPU0rectEX ImageTint #colorGPU#32]
IfFalseAction = [!SetOption MeterGPU0 FontColor #colorTxt#][!SetOption MeterGPU0graph PrimaryColor #colorGPU#][!SetOption MeterGPU0graphEX PrimaryColor #colorGPU#][!SetOption MeterGPU0rect ImageTint #colorGPU#][!SetOption MeterGPU0rectEX ImageTint #colorGPU#]

[MeasureGPU1]
Measure = Plugin
Plugin = MSIAfterburner.dll
DataSource = GPU1 usage
MinValue = 0
MaxValue = 100

[MeasureDSKraw]
Measure = Plugin
Plugin = PerfMon
PerfMonObject = LogicalDisk
PerfMonCounter = % Disk Time
PerfMonInstance = #diskLetter#:

[MeasureDSK]
Measure = Calc
Formula = ((MeasureDSKraw/100000) < 100 ? (MeasureDSKraw/100000) : 100)
MaxValue = 100
Minvalue = 0

[MeasureNET]
Measure = NetTotal
Interface = Best
UpdateDivider = 16
UseBits = 1

[MeasureRAM]
Measure = PhysicalMemory


[MeasureTopCPU]
Measure = Plugin
Plugin=UsageMonitor
Category=Process
Counter=% Processor Time
Index=1
Percent=1
Blacklist=_Total|Idle|dwm|System|system|lsass|svchost

; Meters (rect, rectEX, graph, graphEX, text)
; Rectangle meter
[MeterCPUrect]
Meter = Image
MeterStyle = styleRect
ImageTint = #colorCPU#
x = #x#
y = #y#

[MeterCPUtempRect]
Meter = Image
MeterStyle = styleRect | coordDown
ImageTint = #colorCPU#

[MeterGPU0rect]
Meter = Image
MeterStyle = styleRect | coordRight
Group = GPU0
ImageTint = #colorGPU#

[MeterGPU1rect]
Meter = Image
MeterStyle = styleRect | coordSame
Group = GPU1
ImageTint = #colorGPU#

[MeterGPU0tempRect]
Meter = Image
MeterStyle = styleRect | coordDown
Group = GPU0
ImageTint = #colorGPU#

[MeterGPU1tempRect]
Meter = Image
MeterStyle = styleRect | coordSame
Group = GPU1
ImageTint = #colorGPU#

[MeterDSKrect]
Meter = Image
MeterStyle = styleRect | coordRight
ImageTint = #colorDSK#

[MeterNETrect]
Meter = Image
MeterStyle = styleRect | coordDown
ImageTint = #colorNET#

[MeterRAMrect]
Meter = Image
MeterStyle = styleRect | coordRight
ImageTint = #colorRAM#


; Expanded Rectangle meter
[MeterCPUrectEX]
Meter = Image
MeterStyle = styleRectEX
ImageTint = #colorCPU#
x = #x#
y = #y#

[MeterCPUtempRectEX]
Meter = Image
MeterStyle = styleRectEX | coordDown
ImageTint = #colorCPU#

[MeterGPU0rectEX]
Meter = Image
MeterStyle = styleRectEX | coordRight
ImageTint = #colorGPU#

[MeterGPU1rectEX]
Meter = Image
MeterStyle = styleRectEX | coordSame
ImageTint = #colorGPU#

[MeterGPU0tempRectEX]
Meter = Image
MeterStyle = styleRectEX | coordDown
ImageTint = #colorGPU#

[MeterGPU1tempRectEX]
Meter = Image
MeterStyle = styleRectEX | coordSame
ImageTint = #colorGPU#

[MeterDSKrectEX]
Meter = Image
MeterStyle = styleRectEX | coordRight
ImageTint = #colorDSK#

[MeterNETrectEX]
Meter = Image
MeterStyle = styleRectEX | coordDown
ImageTint = #colorNET#

[MeterRAMrectEX]
Meter = Image
MeterStyle = styleRectEX | coordRight
ImageTint = #colorRAM#



; Graph meter
[MeterCPUgraph]
Meter = Histogram
MeterStyle = styleGraph
MeasureName = MeasureCPU
PrimaryColor = #colorCPU#
x = (#x# + 1)
y = (#y# + 1)

[MeterCPUtempGraph]
Meter = Histogram
MeterStyle = styleGraph | coordDown
MeasureName = MeasureCPUtemp
PrimaryColor = #colorCPU#

[MeterGPU0graph]
Meter = Histogram
MeterStyle = styleGraph | coordRight
MeasureName = MeasureGPU0
Group = GPU0
PrimaryColor = #colorGPU#

[MeterGPU1graph]
Meter = Histogram
MeterStyle = styleGraph | coordSame
MeasureName = MeasureGPU1
Group = GPU1
PrimaryColor = #colorGPU#

[MeterGPU0tempGraph]
Meter = Histogram
MeterStyle = styleGraph | coordDown
MeasureName = MeasureGPU0temp
Group = GPU0
PrimaryColor = #colorGPU#

[MeterGPU1tempGraph]
Meter = Histogram
MeterStyle = styleGraph | coordSame
MeasureName = MeasureGPU1temp
Group = GPU1
PrimaryColor = #colorGPU#

[MeterDSKgraph]
Meter = Histogram
MeterStyle = styleGraph | coordRight
MeasureName = MeasureDSK
PrimaryColor = #colorDSK#

[MeterNETgraph]
Meter = Histogram
MeterStyle = styleGraph | coordDown
MeasureName = MeasureNET
PrimaryColor = #colorNET#
AutoScale = 1

[MeterRAMgraph]
Meter = Histogram
MeterStyle = styleGraph | coordRight
MeasureName = MeasureRAM
PrimaryColor = #colorRAM#

; Expanded Graph meter
[MeterCPUgraphEX]
Meter = Histogram
MeterStyle = styleGraphEX
MeasureName = MeasureCPU
PrimaryColor = #colorCPU#
x = (#x# + 1)
y = (#y# + 1)

[MeterCPUtempGraphEX]
Meter = Histogram
MeterStyle = styleGraphEX | coordDown
MeasureName = MeasureCPUtemp
PrimaryColor = #colorCPU#

[MeterGPU0graphEX]
Meter = Histogram
MeterStyle = styleGraphEX | coordRight
MeasureName = MeasureGPU0
PrimaryColor = #colorGPU#

[MeterGPU1graphEX]
Meter = Histogram
MeterStyle = styleGraphEX | coordSame
MeasureName = MeasureGPU1
PrimaryColor = #colorGPU#

[MeterGPU0tempGraphEX]
Meter = Histogram
MeterStyle = styleGraphEX | coordDown
MeasureName = MeasureGPU0temp
PrimaryColor = #colorGPU#

[MeterGPU1tempGraphEX]
Meter = Histogram
MeterStyle = styleGraphEX | coordSame
MeasureName = MeasureGPU1temp
PrimaryColor = #colorGPU#

[MeterDSKgraphEX]
Meter = Histogram
MeterStyle = styleGraphEX | coordRight
MeasureName = MeasureDSK
PrimaryColor = #colorDSK#

[MeterNETgraphEX]
Meter = Histogram
MeterStyle = styleGraphEX | coordDown
MeasureName = MeasureNET
PrimaryColor = #colorNET#
AutoScale = 1

[MeterRAMgraphEX]
Meter = Histogram
MeterStyle = styleGraphEX | coordRight
MeasureName = MeasureRAM
PrimaryColor = #colorRAM#

[MeterTopCpu%]
Meter = String
MeterStyle = styleText | coordDownRight
MeasureName = MeasureTopCPU
DynamicVariables=1
NumOfDecimals=0
Text="[MeasureTopCPU:0]%"

; Text meter
[MeterCPU]
Meter = String
MeterStyle = styleText
MeasureName = MeasureCPU
Text = %1%
x = (#x# + 38)
y = (#y# + 1)

[MeterCPUtemp]
Meter = String
MeterStyle = styleText | coordDown
MeasureName = MeasureCPUtemp
Text = %1°#tempLetter#

[MeterGPU0]
Meter = String
MeterStyle = styleText | coordRight
MeasureName = MeasureGPU0
Group = GPU0
Text = %1%

[MeterGPU1]
Meter = String
MeterStyle = styleText | coordSame
MeasureName = MeasureGPU1
Group = GPU1
Text = %1%

[MeterGPU0temp]
Meter = String
MeterStyle = styleText | coordDown
MeasureName = MeasureGPU0temp
Group = GPU0
Text = %1°#tempLetter#

[MeterGPU1temp]
Meter = String
MeterStyle = styleText | coordSame
MeasureName = MeasureGPU1temp
Group = GPU1
Text = %1°#tempLetter#

[MeterDSK]
Meter = String
MeterStyle = styleText | coordRight
MeasureName = MeasureDSK
Text = %1%

[MeterNET]
Meter = String
MeterStyle = styleText | coordDown
NumOfDecimals=1
Scale=10000000
Text=%1mb
MeasureName=MeasureNET

[MeterRAM]
Meter = String
MeterStyle = styleText | coordRight
MeasureName = MeasureRAM
Percentual = 1
Text = %1%

[MeterTopCpu]
Meter = String
MeterStyle = styleTextEx | coordDown
MeasureName = MeasureTopCPU


