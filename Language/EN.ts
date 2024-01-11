<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="en">
<context>
    <name>FaultTableInterface</name>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="14"/>
        <source>Fault description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="31"/>
        <source>Please enter search keywords</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="44"/>
        <source>Search</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="57"/>
        <source>DCAC Fault Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="71"/>
        <source>DCDC Module Fault Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="81"/>
        <source>Battery Protection Logic Explanation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="98"/>
        <source>Battery Cut-off Voltage Protection Logic Explanation for Grid-on and grid-off modes:

Grid-on mode:
  When the battery discharges to the cut-off voltage minus 5V (e.g., if the cut-off voltage is 500V, discharge stops at 495V), an alarm &quot;Discharge Not Allowed&quot; will be triggered, and the DCAC converter output power will drop to 0.
  The &quot;Discharge Not Allowed&quot; alarm will be cleared when the battery voltage is greater than the discharge cut-off voltage plus the discharge hysteresis voltage or when the mode is changed to charging.
  When the battery is charged to the upper limit of the charging voltage, an alarm &quot;Charging Not Allowed&quot; will be triggered. If the DCAC is in charging mode, the charging power will drop to 0. If the DCAC is in discharge mode, it will not be affected.
  The &quot;Charging Not Allowed&quot; alarm will be cleared when the battery voltage is lower than the upper limit of the charging voltage minus the charging hysteresis voltage or when it is in discharge mode.

Grid-off mode:
  When the battery discharges to the cut-off voltage minus 5V (e.g., if the cut-off voltage is 500V, discharge stops at 495V), an alarm &quot;Discharge Not Allowed&quot; will be triggered, and the DCAC converter will shut down. The &quot;Discharge Not Allowed&quot; alarm will be cleared when the battery voltage is greater than the discharge cut-off voltage plus the discharge hysteresis voltage. If there is no shutdown command, the system will resume operation.
  When the battery is charged to the upper limit of the charging voltage, an alarm &quot;Charging Not Allowed&quot; will be triggered. If the DCAC is in charging mode or in grid-off discharge mode, it will not be affected.
  The &quot;Charging Not Allowed&quot; alarm will be cleared when the battery voltage is lower than the upper limit of the charging voltage minus the charging hysteresis voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="52"/>
        <source>Alarm name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="52"/>
        <source>Alarm leve</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="52"/>
        <source>Trigger condition</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="53"/>
        <source>Response action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="53"/>
        <source>Whether to reset
automatically and reset time</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>GridExpansion</name>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="14"/>
        <source>Grid expansion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="37"/>
        <source>Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="54"/>
        <source>Logic Explanation:
   When selecting grid expansion mode, the converter will limit the input power of the grid.
Charging and discharging power calculation in grid expansion mode:
   Charging Power: When the converter load power is less than the set grid capacity and the current battery SOC is less than the charging SOC, the converter will charge the battery with the value of (Charging Power = Grid Capacity - Load Power). When the battery SOC reaches the charging stop SOC or the battery is prohibited from charging, the charging process will stop. When the battery SOC reaches 90% and the current charging power exceeds 80% of the maximum machine output power, the charging power will be set as (Charging Power = Maximum Machine Output Power / 2).
   Discharging Power: When the converter load power is greater than the set grid capacity, the converter will discharge power to compensate for the insufficient grid power, with the value of (Discharging Power = Load Power - Grid Capacity). When the battery&apos;s SOC is less than the discharging stop SOC or the battery is prohibited from discharging, the converter will maintain zero power operation. When the battery continues to discharge to reach the Depth of Discharge (DOD), DOD protection will be applied.
   Note: The charging and discharging power will not exceed the allowed charging power and discharging power stated in the battery data sheet. Constant power setting is invalid in grid expansion mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="87"/>
        <source>Generator Charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="95"/>
        <location filename="../GridExpansion/gridexpansion.ui" line="111"/>
        <location filename="../GridExpansion/gridexpansion.ui" line="127"/>
        <location filename="../GridExpansion/gridexpansion.ui" line="143"/>
        <source>%</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="103"/>
        <source>Grid Charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="119"/>
        <source>Charge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="135"/>
        <source>Discharge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="151"/>
        <source>Grid capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="159"/>
        <source>kW</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="173"/>
        <source>Logic Diagram</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="246"/>
        <source>Reload</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="277"/>
        <source>Previous
Page</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="39"/>
        <source>Name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="39"/>
        <source>Value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="39"/>
        <source>Unit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="47"/>
        <source>0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="50"/>
        <source>Charging SOC of Diesel Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="51"/>
        <source>Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="54"/>
        <source>Charging SOC of Grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="55"/>
        <source>Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="58"/>
        <source>Charging Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="59"/>
        <source>Charging Stop SOC: In grid expansion mode, when the battery is charging, it will stop charging when the battery SOC is greater than this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="62"/>
        <source>Discharging Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="63"/>
        <source>Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="66"/>
        <source>Grid Capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.cpp" line="67"/>
        <source>Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>MEGAWin</name>
    <message>
        <location filename="../win.ui" line="158"/>
        <location filename="../win.ui" line="2851"/>
        <source>Change
Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="187"/>
        <source>Basic settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="235"/>
        <source>Function Setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="281"/>
        <location filename="../win.ui" line="331"/>
        <location filename="../win.ui" line="858"/>
        <location filename="../win.ui" line="918"/>
        <location filename="../win.ui" line="1972"/>
        <location filename="../win.ui" line="2032"/>
        <location filename="../win.ui" line="4453"/>
        <location filename="../win.ui" line="4638"/>
        <location filename="../win.ui" line="4683"/>
        <location filename="../win.ui" line="4728"/>
        <location filename="../win.ui" line="4778"/>
        <location filename="../win.ui" line="5049"/>
        <location filename="../win.ui" line="5094"/>
        <location filename="../win.ui" line="8676"/>
        <location filename="../win.ui" line="8716"/>
        <location filename="../win.ui" line="9213"/>
        <location filename="../win.ui" line="9308"/>
        <location filename="../win.cpp" line="2408"/>
        <location filename="../win.cpp" line="3541"/>
        <location filename="../win.cpp" line="3550"/>
        <source>1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="286"/>
        <location filename="../win.ui" line="336"/>
        <location filename="../win.ui" line="863"/>
        <location filename="../win.ui" line="923"/>
        <location filename="../win.ui" line="1977"/>
        <location filename="../win.ui" line="2037"/>
        <location filename="../win.ui" line="4458"/>
        <location filename="../win.ui" line="4643"/>
        <location filename="../win.ui" line="4688"/>
        <location filename="../win.ui" line="4733"/>
        <location filename="../win.ui" line="4783"/>
        <location filename="../win.ui" line="5054"/>
        <location filename="../win.ui" line="5099"/>
        <location filename="../win.ui" line="8681"/>
        <location filename="../win.ui" line="8724"/>
        <location filename="../win.ui" line="9218"/>
        <location filename="../win.ui" line="9313"/>
        <source>2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="291"/>
        <location filename="../win.ui" line="341"/>
        <location filename="../win.ui" line="868"/>
        <location filename="../win.ui" line="928"/>
        <location filename="../win.ui" line="1982"/>
        <location filename="../win.ui" line="2042"/>
        <location filename="../win.ui" line="4463"/>
        <location filename="../win.ui" line="4648"/>
        <location filename="../win.ui" line="4738"/>
        <location filename="../win.ui" line="5059"/>
        <location filename="../win.ui" line="5104"/>
        <location filename="../win.ui" line="8686"/>
        <location filename="../win.ui" line="8732"/>
        <location filename="../win.ui" line="9223"/>
        <location filename="../win.ui" line="9318"/>
        <source>3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="296"/>
        <location filename="../win.ui" line="346"/>
        <location filename="../win.ui" line="873"/>
        <location filename="../win.ui" line="933"/>
        <location filename="../win.ui" line="1987"/>
        <location filename="../win.ui" line="2047"/>
        <location filename="../win.ui" line="4468"/>
        <location filename="../win.ui" line="4653"/>
        <location filename="../win.ui" line="4743"/>
        <location filename="../win.ui" line="5064"/>
        <location filename="../win.ui" line="5109"/>
        <location filename="../win.ui" line="8691"/>
        <location filename="../win.ui" line="8740"/>
        <location filename="../win.ui" line="9228"/>
        <location filename="../win.ui" line="9323"/>
        <source>4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="301"/>
        <location filename="../win.ui" line="351"/>
        <location filename="../win.ui" line="878"/>
        <location filename="../win.ui" line="938"/>
        <location filename="../win.ui" line="1992"/>
        <location filename="../win.ui" line="2052"/>
        <location filename="../win.ui" line="4473"/>
        <location filename="../win.ui" line="4658"/>
        <location filename="../win.ui" line="4748"/>
        <location filename="../win.ui" line="5069"/>
        <location filename="../win.ui" line="5114"/>
        <location filename="../win.ui" line="8696"/>
        <location filename="../win.ui" line="8745"/>
        <location filename="../win.ui" line="9233"/>
        <location filename="../win.ui" line="9328"/>
        <source>5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="306"/>
        <location filename="../win.ui" line="356"/>
        <location filename="../win.ui" line="883"/>
        <location filename="../win.ui" line="943"/>
        <location filename="../win.ui" line="1997"/>
        <location filename="../win.ui" line="2057"/>
        <location filename="../win.ui" line="4478"/>
        <location filename="../win.ui" line="4663"/>
        <location filename="../win.ui" line="4753"/>
        <location filename="../win.ui" line="5074"/>
        <location filename="../win.ui" line="5119"/>
        <location filename="../win.ui" line="8701"/>
        <location filename="../win.ui" line="8750"/>
        <location filename="../win.ui" line="9238"/>
        <location filename="../win.ui" line="9333"/>
        <source>6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="311"/>
        <location filename="../win.ui" line="361"/>
        <location filename="../win.ui" line="888"/>
        <location filename="../win.ui" line="948"/>
        <location filename="../win.ui" line="2002"/>
        <location filename="../win.ui" line="4483"/>
        <location filename="../win.ui" line="4668"/>
        <location filename="../win.ui" line="4758"/>
        <location filename="../win.ui" line="5079"/>
        <location filename="../win.ui" line="8706"/>
        <location filename="../win.ui" line="9243"/>
        <source>7</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="316"/>
        <location filename="../win.ui" line="366"/>
        <location filename="../win.ui" line="893"/>
        <location filename="../win.ui" line="953"/>
        <location filename="../win.ui" line="2007"/>
        <location filename="../win.ui" line="4488"/>
        <location filename="../win.ui" line="4673"/>
        <location filename="../win.ui" line="4763"/>
        <location filename="../win.ui" line="5084"/>
        <location filename="../win.ui" line="8711"/>
        <location filename="../win.ui" line="9248"/>
        <location filename="../win.ui" line="9935"/>
        <source>8</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="321"/>
        <location filename="../win.ui" line="371"/>
        <location filename="../win.ui" line="898"/>
        <location filename="../win.ui" line="958"/>
        <location filename="../win.ui" line="2012"/>
        <location filename="../win.ui" line="4493"/>
        <location filename="../win.ui" line="4768"/>
        <location filename="../win.ui" line="5089"/>
        <location filename="../win.ui" line="9253"/>
        <location filename="../win.ui" line="9940"/>
        <source>9</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="326"/>
        <location filename="../win.ui" line="903"/>
        <location filename="../win.ui" line="2017"/>
        <location filename="../win.ui" line="4498"/>
        <location filename="../win.ui" line="4678"/>
        <location filename="../win.ui" line="4773"/>
        <location filename="../win.ui" line="9258"/>
        <source>10</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="908"/>
        <location filename="../win.ui" line="2022"/>
        <location filename="../win.ui" line="9263"/>
        <source>11</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="913"/>
        <location filename="../win.ui" line="2027"/>
        <location filename="../win.ui" line="9268"/>
        <source>12</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="376"/>
        <location filename="../win.cpp" line="4722"/>
        <source>Battery type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="384"/>
        <location filename="../win.ui" line="400"/>
        <location filename="../win.ui" line="416"/>
        <location filename="../win.ui" line="432"/>
        <location filename="../win.ui" line="448"/>
        <location filename="../win.ui" line="464"/>
        <location filename="../win.ui" line="480"/>
        <location filename="../win.ui" line="512"/>
        <location filename="../win.ui" line="528"/>
        <location filename="../win.ui" line="560"/>
        <location filename="../win.ui" line="608"/>
        <location filename="../win.ui" line="624"/>
        <location filename="../win.ui" line="664"/>
        <location filename="../win.ui" line="701"/>
        <location filename="../win.ui" line="992"/>
        <location filename="../win.ui" line="1013"/>
        <location filename="../win.ui" line="1066"/>
        <location filename="../win.ui" line="1114"/>
        <location filename="../win.ui" line="1162"/>
        <location filename="../win.ui" line="1210"/>
        <location filename="../win.ui" line="1226"/>
        <location filename="../win.ui" line="1242"/>
        <location filename="../win.ui" line="1258"/>
        <location filename="../win.ui" line="1274"/>
        <location filename="../win.ui" line="1290"/>
        <location filename="../win.ui" line="1306"/>
        <location filename="../win.ui" line="1322"/>
        <location filename="../win.ui" line="1359"/>
        <location filename="../win.ui" line="1391"/>
        <location filename="../win.ui" line="1444"/>
        <location filename="../win.ui" line="1858"/>
        <location filename="../win.ui" line="1866"/>
        <location filename="../win.ui" line="1874"/>
        <location filename="../win.ui" line="1882"/>
        <location filename="../win.ui" line="1890"/>
        <location filename="../win.ui" line="1898"/>
        <location filename="../win.ui" line="1906"/>
        <location filename="../win.ui" line="1914"/>
        <location filename="../win.ui" line="8771"/>
        <location filename="../win.ui" line="8795"/>
        <location filename="../win.ui" line="8843"/>
        <location filename="../win.ui" line="8867"/>
        <location filename="../win.ui" line="8891"/>
        <location filename="../win.ui" line="8915"/>
        <location filename="../win.ui" line="8963"/>
        <location filename="../win.ui" line="9586"/>
        <location filename="../win.ui" line="9983"/>
        <location filename="../win.ui" line="10015"/>
        <location filename="../win.ui" line="10162"/>
        <location filename="../win.ui" line="10226"/>
        <location filename="../win.ui" line="10290"/>
        <location filename="../win.ui" line="10354"/>
        <source>-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4887"/>
        <source>ProtocolVersion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="424"/>
        <source>BMS Comm. type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="496"/>
        <location filename="../win.ui" line="544"/>
        <location filename="../win.ui" line="592"/>
        <location filename="../win.ui" line="640"/>
        <source>bps</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4896"/>
        <source>UserPassPort</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="472"/>
        <location filename="../win.cpp" line="4742"/>
        <source>Power control type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="488"/>
        <location filename="../win.cpp" line="4823"/>
        <source>serial port 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="520"/>
        <source>EMS Comm. type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="536"/>
        <location filename="../win.cpp" line="4832"/>
        <source>serial port 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="552"/>
        <location filename="../win.cpp" line="4914"/>
        <source>Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="568"/>
        <location filename="../win.cpp" line="4764"/>
        <source>Output power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="576"/>
        <location filename="../win.ui" line="717"/>
        <location filename="../win.ui" line="1050"/>
        <location filename="../win.ui" line="6895"/>
        <location filename="../win.ui" line="6922"/>
        <location filename="../win.ui" line="8819"/>
        <location filename="../win.ui" line="9554"/>
        <location filename="../win.ui" line="9602"/>
        <location filename="../win.ui" line="9618"/>
        <location filename="../win.ui" line="9730"/>
        <source>kW</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="584"/>
        <location filename="../win.cpp" line="4842"/>
        <source>serial port 4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="600"/>
        <source>System upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="632"/>
        <location filename="../win.cpp" line="4851"/>
        <source>serial port 5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="648"/>
        <location filename="../win.cpp" line="4936"/>
        <source>Sounds</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="725"/>
        <location filename="../win.cpp" line="4869"/>
        <source>Can port 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="680"/>
        <location filename="../win.ui" line="733"/>
        <source>kbps</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9594"/>
        <location filename="../win.cpp" line="3686"/>
        <source>Charge power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="773"/>
        <location filename="../win.cpp" line="4878"/>
        <source>Can port 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9610"/>
        <location filename="../win.cpp" line="3695"/>
        <source>Discharge power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9434"/>
        <source>Charge Vol. upper Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1146"/>
        <location filename="../win.ui" line="1194"/>
        <location filename="../win.ui" line="6118"/>
        <location filename="../win.ui" line="9059"/>
        <location filename="../win.ui" line="9410"/>
        <location filename="../win.ui" line="9442"/>
        <location filename="../win.ui" line="9474"/>
        <location filename="../win.ui" line="9490"/>
        <location filename="../win.ui" line="9506"/>
        <location filename="../win.ui" line="9522"/>
        <location filename="../win.ui" line="9999"/>
        <location filename="../win.ui" line="10031"/>
        <location filename="../win.ui" line="10047"/>
        <location filename="../win.ui" line="10092"/>
        <location filename="../win.ui" line="10108"/>
        <location filename="../win.ui" line="10306"/>
        <location filename="../win.ui" line="10370"/>
        <source>V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9498"/>
        <source>Discharge Vol. lower Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="815"/>
        <source>System parameter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="971"/>
        <source>kW/s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="979"/>
        <location filename="../win.cpp" line="5089"/>
        <source>Machine type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1000"/>
        <location filename="../win.cpp" line="5202"/>
        <source>Module Number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1034"/>
        <location filename="../win.ui" line="1082"/>
        <location filename="../win.ui" line="1098"/>
        <location filename="../win.ui" line="1338"/>
        <source>Hz</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1042"/>
        <location filename="../win.cpp" line="5098"/>
        <source>Machine capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1058"/>
        <location filename="../win.cpp" line="5211"/>
        <source>Restore factory</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1090"/>
        <source>Output Fre. grade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1202"/>
        <location filename="../win.cpp" line="5238"/>
        <source>Clear Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1130"/>
        <location filename="../win.ui" line="1178"/>
        <location filename="../win.ui" line="6172"/>
        <location filename="../win.ui" line="6199"/>
        <location filename="../win.ui" line="9346"/>
        <location filename="../win.ui" line="9362"/>
        <location filename="../win.ui" line="9378"/>
        <location filename="../win.ui" line="9394"/>
        <location filename="../win.ui" line="9634"/>
        <location filename="../win.ui" line="9650"/>
        <location filename="../win.ui" line="9666"/>
        <location filename="../win.ui" line="9682"/>
        <location filename="../win.ui" line="9698"/>
        <location filename="../win.ui" line="9714"/>
        <source>%</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1138"/>
        <source>Output vol. level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1218"/>
        <location filename="../win.cpp" line="5025"/>
        <source>HVRT enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1234"/>
        <location filename="../win.cpp" line="5134"/>
        <source>Output reactive power mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1250"/>
        <location filename="../win.cpp" line="5034"/>
        <source>LVRT enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1282"/>
        <location filename="../win.cpp" line="5043"/>
        <source>AFD enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1330"/>
        <location filename="../win.cpp" line="5165"/>
        <source>Primary FM dead zone</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1314"/>
        <location filename="../win.cpp" line="5053"/>
        <source>Insulation detection enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1367"/>
        <location filename="../win.cpp" line="5174"/>
        <source>PFM coeff</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1375"/>
        <source>kW/Hz</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1351"/>
        <location filename="../win.cpp" line="5062"/>
        <source>PrimaryFreq enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1399"/>
        <location filename="../win.cpp" line="5183"/>
        <source>Grid recover time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="749"/>
        <location filename="../win.ui" line="797"/>
        <location filename="../win.ui" line="1407"/>
        <source>s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="41"/>
        <source>PCS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="440"/>
        <location filename="../win.cpp" line="4813"/>
        <source>Modbus Offset Address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="456"/>
        <source>User PassPort</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="656"/>
        <location filename="../win.cpp" line="4784"/>
        <source>EMS CAN Protocol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="688"/>
        <location filename="../win.cpp" line="4945"/>
        <source>Energy Meter Model</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="741"/>
        <source>BMS Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="789"/>
        <source>EMS Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1021"/>
        <location filename="../win.cpp" line="4989"/>
        <source>ULFV</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1074"/>
        <location filename="../win.cpp" line="4998"/>
        <source>LLFV</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1106"/>
        <source>Backup setup parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1154"/>
        <source>Restore backup setup parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1186"/>
        <location filename="../win.cpp" line="5125"/>
        <source>Transformer Turns Ratio</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1298"/>
        <location filename="../win.cpp" line="5155"/>
        <source>System Anti-Reverse Flow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1383"/>
        <location filename="../win.cpp" line="5071"/>
        <source>Inertia enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1415"/>
        <location filename="../win.cpp" line="5080"/>
        <source>CV parallel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1436"/>
        <location filename="../win.cpp" line="5192"/>
        <source>DynamicCap</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1462"/>
        <source>External device</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1502"/>
        <source>DI_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1507"/>
        <source>DI_2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1512"/>
        <source>DI_3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1517"/>
        <source>DI_4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1522"/>
        <source>DI_5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1527"/>
        <source>DI_6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1547"/>
        <source>Enable/Disable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1552"/>
        <source>NC/NO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1557"/>
        <location filename="../win.ui" line="1843"/>
        <source>Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1562"/>
        <source>Function description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5427"/>
        <source>Access Control</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5435"/>
        <source>Full Power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5443"/>
        <source>Smoke</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5451"/>
        <source>Temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1642"/>
        <location filename="../win.ui" line="1686"/>
        <location filename="../win.ui" line="1730"/>
        <source>N_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1664"/>
        <source>Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1708"/>
        <location filename="../win.ui" line="1752"/>
        <source>Reserve</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1773"/>
        <source>BMS protection</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1813"/>
        <source>DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1818"/>
        <location filename="../win.cpp" line="5474"/>
        <source>Prohibit charging</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1823"/>
        <location filename="../win.cpp" line="5483"/>
        <source>Prohibit discharging</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1932"/>
        <source>Debug</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2062"/>
        <location filename="../win.cpp" line="5581"/>
        <source>Debug variable 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2070"/>
        <source>1.5V Voltage revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2078"/>
        <source>INV A inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2086"/>
        <location filename="../win.cpp" line="5589"/>
        <source>Debug variable 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2094"/>
        <source> Bus Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2102"/>
        <source>INV B inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2110"/>
        <location filename="../win.cpp" line="5597"/>
        <source>Debug variable 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2118"/>
        <source>Grid A/AB Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2126"/>
        <source>INV C inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2134"/>
        <source>Debug variable 1 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2142"/>
        <source>Grid B/BC Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2150"/>
        <location filename="../win.cpp" line="5781"/>
        <source>INV On off flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2158"/>
        <source>Debug variable 2 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2166"/>
        <source>Grid C/CA Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2174"/>
        <location filename="../win.cpp" line="5789"/>
        <source>Logic state</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2182"/>
        <source>Debug variable 3 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2190"/>
        <source>Output A Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2198"/>
        <location filename="../win.cpp" line="5797"/>
        <source>INV flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2206"/>
        <source>Debug memery var. 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2214"/>
        <source>Output B Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2222"/>
        <location filename="../win.cpp" line="5805"/>
        <source>Grid flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2230"/>
        <source>Debug memery var. 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2238"/>
        <source>Output C Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2246"/>
        <location filename="../win.cpp" line="5813"/>
        <source>Grid protect flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2254"/>
        <source>Debug memery var. 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2262"/>
        <source>INV A Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2270"/>
        <location filename="../win.cpp" line="5821"/>
        <source>Bat flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2278"/>
        <source>Input Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2286"/>
        <source>INV B Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2294"/>
        <location filename="../win.cpp" line="5829"/>
        <source>DC bus flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2302"/>
        <source>Input. Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2310"/>
        <source>INV C Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2318"/>
        <location filename="../win.cpp" line="5837"/>
        <source>INT main flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2326"/>
        <location filename="../win.cpp" line="5845"/>
        <source>parallel signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2344"/>
        <source>MonitorDebug</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2395"/>
        <source>DO control:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2407"/>
        <source>DO_TurnON_btn</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2420"/>
        <source>DO_TurnOFF_btn</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2456"/>
        <source>Soft start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2481"/>
        <source>Local_on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2468"/>
        <source>Local_off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2540"/>
        <location filename="../win.cpp" line="5916"/>
        <source>test data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2893"/>
        <source>100kW - TS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3599"/>
        <location filename="../win.ui" line="3716"/>
        <location filename="../win.ui" line="3777"/>
        <location filename="../win.ui" line="3838"/>
        <location filename="../win.ui" line="4102"/>
        <location filename="../win.ui" line="4118"/>
        <location filename="../win.ui" line="4134"/>
        <source>0A</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3561"/>
        <location filename="../win.ui" line="3700"/>
        <location filename="../win.ui" line="3761"/>
        <location filename="../win.ui" line="3822"/>
        <location filename="../win.ui" line="3948"/>
        <location filename="../win.ui" line="3964"/>
        <location filename="../win.ui" line="3980"/>
        <source>0V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3523"/>
        <source>40%</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3507"/>
        <source>SOC:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2649"/>
        <location filename="../win.cpp" line="2337"/>
        <source>Begin</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4824"/>
        <source>Converter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4864"/>
        <source>Grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4904"/>
        <source>Load</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5124"/>
        <location filename="../win.cpp" line="1894"/>
        <location filename="../win.cpp" line="1897"/>
        <source>DC input breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5129"/>
        <location filename="../win.cpp" line="1902"/>
        <location filename="../win.cpp" line="3364"/>
        <source>converter available</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5134"/>
        <source>DO1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5139"/>
        <location filename="../win.cpp" line="1894"/>
        <location filename="../win.cpp" line="1897"/>
        <location filename="../win.cpp" line="3310"/>
        <source>DC contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5144"/>
        <location filename="../win.cpp" line="1902"/>
        <location filename="../win.cpp" line="3373"/>
        <source>DC Soft start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5149"/>
        <location filename="../win.cpp" line="1905"/>
        <location filename="../win.cpp" line="3427"/>
        <source>DO2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5154"/>
        <location filename="../win.cpp" line="1895"/>
        <location filename="../win.cpp" line="1898"/>
        <location filename="../win.cpp" line="3319"/>
        <source>Output contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5159"/>
        <location filename="../win.cpp" line="1903"/>
        <location filename="../win.cpp" line="3382"/>
        <source>converter status</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5164"/>
        <location filename="../win.cpp" line="1906"/>
        <location filename="../win.cpp" line="3436"/>
        <source>DO3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5169"/>
        <location filename="../win.cpp" line="1895"/>
        <location filename="../win.cpp" line="1898"/>
        <source>Output breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5174"/>
        <location filename="../win.cpp" line="1903"/>
        <source>Reactive power Regulation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5179"/>
        <source>DI1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5184"/>
        <location filename="../win.cpp" line="1899"/>
        <location filename="../win.cpp" line="3337"/>
        <source>Grid contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5189"/>
        <location filename="../win.cpp" line="1903"/>
        <location filename="../win.cpp" line="3400"/>
        <source>LVRT</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5194"/>
        <source>DI2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5199"/>
        <location filename="../win.cpp" line="1895"/>
        <location filename="../win.cpp" line="1899"/>
        <source>Grid breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5212"/>
        <source>DI3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5222"/>
        <source>DI4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5227"/>
        <source>DI5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5232"/>
        <source>DI6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5407"/>
        <source>Battery Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7057"/>
        <source>prompt:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7085"/>
        <source>Normal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7317"/>
        <source>Alarm level:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7401"/>
        <location filename="../win.ui" line="7460"/>
        <location filename="../win.cpp" line="3391"/>
        <location filename="../win.cpp" line="3400"/>
        <location filename="../win.cpp" line="3409"/>
        <location filename="../win.cpp" line="3427"/>
        <location filename="../win.cpp" line="3436"/>
        <location filename="../win.cpp" line="3445"/>
        <location filename="../win.cpp" line="3454"/>
        <location filename="../win.cpp" line="3463"/>
        <location filename="../win.cpp" line="3472"/>
        <location filename="../win.cpp" line="3481"/>
        <location filename="../win.cpp" line="3490"/>
        <location filename="../win.cpp" line="3598"/>
        <location filename="../win.cpp" line="5155"/>
        <location filename="../win.cpp" line="5272"/>
        <source>Disable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4503"/>
        <location filename="../win.ui" line="4513"/>
        <location filename="../win.ui" line="5579"/>
        <location filename="../win.ui" line="6351"/>
        <location filename="../win.ui" line="9945"/>
        <location filename="../win.ui" line="9960"/>
        <location filename="../win.cpp" line="1074"/>
        <location filename="../win.cpp" line="1212"/>
        <location filename="../win.cpp" line="1274"/>
        <location filename="../win.cpp" line="1321"/>
        <location filename="../win.cpp" line="1386"/>
        <location filename="../win.cpp" line="1923"/>
        <source>Name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4508"/>
        <location filename="../win.ui" line="4518"/>
        <location filename="../win.ui" line="5859"/>
        <location filename="../win.ui" line="6595"/>
        <location filename="../win.ui" line="9950"/>
        <location filename="../win.ui" line="9965"/>
        <location filename="../win.cpp" line="1074"/>
        <location filename="../win.cpp" line="1212"/>
        <location filename="../win.cpp" line="1274"/>
        <location filename="../win.cpp" line="1321"/>
        <location filename="../win.cpp" line="1923"/>
        <source>Value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4963"/>
        <source>120</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6088"/>
        <location filename="../win.ui" line="6814"/>
        <location filename="../win.ui" line="9955"/>
        <location filename="../win.ui" line="9970"/>
        <location filename="../win.cpp" line="1074"/>
        <source>Unit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6145"/>
        <location filename="../win.ui" line="6841"/>
        <location filename="../win.ui" line="6868"/>
        <location filename="../win.ui" line="9011"/>
        <location filename="../win.ui" line="9538"/>
        <location filename="../win.ui" line="9570"/>
        <source>A</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6949"/>
        <location filename="../win.ui" line="6976"/>
        <source>kWh</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5612"/>
        <source>Bat voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1532"/>
        <source>DO_1   </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1537"/>
        <source>DO_2    </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1542"/>
        <source>DO_3    </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4299"/>
        <source>Converter Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4938"/>
        <location filename="../win.cpp" line="5900"/>
        <source>Converter State</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5257"/>
        <source>Converter Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5642"/>
        <location filename="../win.cpp" line="2871"/>
        <source>Bat current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5672"/>
        <location filename="../win.cpp" line="2875"/>
        <source>SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5702"/>
        <location filename="../win.cpp" line="2879"/>
        <source>SOH</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5732"/>
        <source>Cell voltage (max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5762"/>
        <source>Cell voltage (min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5792"/>
        <source>Cell temp. (max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5822"/>
        <source>Cell temp. (min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3568"/>
        <source>600</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3559"/>
        <source>100</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6226"/>
        <location filename="../win.ui" line="6253"/>
        <location filename="../win.ui" line="9426"/>
        <location filename="../win.ui" line="9458"/>
        <location filename="../win.ui" line="9746"/>
        <location filename="../win.ui" line="9762"/>
        <source>mV</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6280"/>
        <location filename="../win.ui" line="6307"/>
        <source>℃</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6378"/>
        <location filename="../win.cpp" line="2899"/>
        <source>Charging current limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6405"/>
        <location filename="../win.cpp" line="2903"/>
        <source>Discharging current limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6432"/>
        <location filename="../win.cpp" line="2907"/>
        <source>Allowable charging power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6460"/>
        <location filename="../win.cpp" line="2911"/>
        <source>Allowable discharging power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6487"/>
        <location filename="../win.cpp" line="2915"/>
        <source>Allowable charging energy</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6514"/>
        <location filename="../win.cpp" line="2919"/>
        <source>Allowable discharging energy</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7141"/>
        <source>Level1 </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7197"/>
        <source>Level2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7253"/>
        <source>Level3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7373"/>
        <source>Charging
enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7432"/>
        <source>Discharging
enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7506"/>
        <source>Data report</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7568"/>
        <source>Discharge:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7596"/>
        <source>1.1
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7616"/>
        <location filename="../win.ui" line="7826"/>
        <source>Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7653"/>
        <location filename="../win.ui" line="7701"/>
        <source>339
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7667"/>
        <location filename="../win.ui" line="7874"/>
        <source>Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7715"/>
        <location filename="../win.ui" line="7922"/>
        <source>Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7749"/>
        <source>585.1
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7763"/>
        <location filename="../win.ui" line="7970"/>
        <source>Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7784"/>
        <source>Charge:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7812"/>
        <source>2.4
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7860"/>
        <location filename="../win.ui" line="7908"/>
        <source>2.6
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7956"/>
        <source>184.2
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8061"/>
        <source>M  -</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8080"/>
        <source>Y  -</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8116"/>
        <source>M  +</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8135"/>
        <source>Y  +</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8164"/>
        <source>Export Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8225"/>
        <source>Note:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8242"/>
        <source>Out put file:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8278"/>
        <source>Log.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8296"/>
        <source>Report.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8341"/>
        <source>Data To Export</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8596"/>
        <source>History Record</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8480"/>
        <location filename="../win.ui" line="8615"/>
        <location filename="../win.cpp" line="2249"/>
        <source>Operation Log</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8645"/>
        <source>Parameter setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8779"/>
        <location filename="../win.cpp" line="3579"/>
        <source>Control mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8803"/>
        <source>Constant power (AC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8827"/>
        <location filename="../win.cpp" line="3589"/>
        <source>Machine number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8875"/>
        <source>Parallel </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8851"/>
        <source>Work mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5295"/>
        <source>Please click on &apos;Alarm Information&apos; to enter the query interface
and view the details of the alarm information you have encountered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5356"/>
        <source>Alarm
Information</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8899"/>
        <location filename="../win.cpp" line="3541"/>
        <source>Output power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8947"/>
        <location filename="../win.cpp" line="3550"/>
        <source>Output reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8995"/>
        <location filename="../win.cpp" line="3559"/>
        <source>Constant current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9043"/>
        <location filename="../win.cpp" line="3568"/>
        <source>Constant voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9153"/>
        <source>  Title</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9173"/>
        <source>Return</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9182"/>
        <source>Battery setup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9800"/>
        <location filename="../win.cpp" line="2325"/>
        <source>Battery power on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9819"/>
        <location filename="../win.cpp" line="2329"/>
        <source>Battery power off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9900"/>
        <location filename="../win.ui" line="9905"/>
        <location filename="../win.ui" line="9910"/>
        <location filename="../win.ui" line="9915"/>
        <location filename="../win.ui" line="9920"/>
        <location filename="../win.ui" line="9925"/>
        <location filename="../win.ui" line="9930"/>
        <source>New Row</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9975"/>
        <location filename="../win.cpp" line="3859"/>
        <source>Capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9991"/>
        <source>Grid off EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10007"/>
        <source>Cell number(2V)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10023"/>
        <source>Grid on EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10039"/>
        <location filename="../win.cpp" line="3869"/>
        <source>Battery float voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10055"/>
        <source>Shutdown voltage point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10100"/>
        <location filename="../win.cpp" line="3874"/>
        <source>Battery filling voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10116"/>
        <source>Mending center point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10170"/>
        <location filename="../win.cpp" line="3879"/>
        <source>Charge limiting value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10178"/>
        <location filename="../win.ui" line="10242"/>
        <location filename="../win.ui" line="10403"/>
        <location filename="../win.ui" line="10419"/>
        <source>C</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10186"/>
        <source>Temperature filling coefficient</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10234"/>
        <location filename="../win.cpp" line="3884"/>
        <source>Discharge limiting value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10250"/>
        <source>Mending allowable setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10314"/>
        <source>Temperature alarm upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10378"/>
        <location filename="../win.cpp" line="3909"/>
        <source>Uniform charging and flushing current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10411"/>
        <location filename="../win.cpp" line="3914"/>
        <source>Float turn uniform charging current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9338"/>
        <source>DOD_OnGrid:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8260"/>
        <source>Record.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8381"/>
        <source>status:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8414"/>
        <source>u disk disconnect!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8449"/>
        <location filename="../win.cpp" line="2245"/>
        <source>Historical Failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8514"/>
        <location filename="../win.cpp" line="2253"/>
        <source>Electricity Statistical Table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8545"/>
        <location filename="../win.cpp" line="2257"/>
        <source>Eject U disk</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8755"/>
        <source>Grid conected mode of the converter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9354"/>
        <source>Turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9370"/>
        <source>DOD_OffGrid:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9386"/>
        <source>Turn off SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9402"/>
        <source>Charge Vol. upper Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9418"/>
        <source>Turn on cell vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9466"/>
        <source>Discharge Vol. lower Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9450"/>
        <source>Turn off cell vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9530"/>
        <source>Charge Cur. Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9482"/>
        <source>Turn on total vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9626"/>
        <location filename="../win.cpp" line="3704"/>
        <source>Generator turn off SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9514"/>
        <source>Turn off total vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9642"/>
        <source>Generator turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9546"/>
        <source>UPS charge power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9658"/>
        <source>Generator charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9578"/>
        <source>Monthly cycle time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5411"/>
        <source>Dry Contact EPO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5419"/>
        <source>Dry Contact Shutdown</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1828"/>
        <source>Level 1 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1833"/>
        <source>Level 2 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1838"/>
        <source>Level 3 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1848"/>
        <source>Charge power(kW)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1853"/>
        <source>Discharge power(kW)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2578"/>
        <source>PortMessage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2595"/>
        <source>Can 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2615"/>
        <source>Display mode:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2623"/>
        <source>Displayed on screen</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2628"/>
        <source>Write to USB drive</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2671"/>
        <location filename="../win.cpp" line="2353"/>
        <source>2023-09-27  17:27:56.201  CAN 2: Tx  Len=8  ID=9f000100 00 00 00 00 00 00 00 00
2023-09-27  17:27:56.302  CAN 2: Rx  Len=8  ID=9f000301 0d 00 64 00 70 17 e8 03
2023-09-27  17:27:57.105  CAN 2: Rx  Len=8  ID=9f000300 40 1f a0 0f e8 03 e8 03
2023-09-27  17:27:57.206  CAN 2: Tx  Len=8  ID=9f000100 00 00 00 00 00 00 00 00
2023-09-27  17:27:57.307  CAN 2: Rx  Len=8  ID=9f000301 0d 00 64 00 70 17 e8 03
2023-09-27  17:27:57.910  CAN 2: Rx  Len=8  ID=9f000304 40 1f a0 0f 00 00 00 00
2023-09-27  17:27:58.110  CAN 2: Rx  Len=8  ID=9f000300 40 1f a0 0f e8 03 e8 03
2023-09-27  17:27:58.211  CAN 2: Tx  Len=8  ID=9f000100 00 00 00 00 00 00 00 00
2023-09-27  17:27:58.312  CAN 2: Rx  Len=8  ID=9f000301 0d 00 64 00 70 17 e8 03
2023-09-27  17:27:58.915  CAN 2: Rx  Len=8  ID=9f000304 40 1f a0 0f 00 00 00 00
2023-09-27  17:27:59.116  CAN 2: Rx  Len=8  ID=9f000300 40 1f a0 0f e8 03 e8 03
2023-09-27  17:27:59.217  CAN 2: Tx  Len=8  ID=9f000100 00 00 00 00 00 00 00 00
2023-09-27  17:27:59.317  CAN 2: Rx  Len=8  ID=9f000301 0d 00 64 00 70 17 e8 03
2023-09-27  17:27:59.920  CAN 2: Rx  Len=8  ID=9f000304 40 1f a0 0f 00 00 00 00
2023-09-27  17:28:00.121  CAN 2: Rx  Len=8  ID=9f000300 40 1f a0 0f e8 03 e8 03</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5204"/>
        <location filename="../win.cpp" line="3409"/>
        <source>Forced charge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9273"/>
        <source>13</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9278"/>
        <source>14</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9283"/>
        <source>15</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9288"/>
        <source>16</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9293"/>
        <source>17</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9298"/>
        <source>18</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9303"/>
        <source>19</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9562"/>
        <source>Discharge Cur. Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9674"/>
        <location filename="../win.cpp" line="3731"/>
        <source>Grid charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9690"/>
        <location filename="../win.cpp" line="3740"/>
        <source>Charge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9706"/>
        <location filename="../win.cpp" line="3749"/>
        <source>Discharge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9722"/>
        <source>Grid capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9738"/>
        <location filename="../win.cpp" line="3767"/>
        <source>Force Charge start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9754"/>
        <location filename="../win.cpp" line="3776"/>
        <source>Force Charge stop</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9831"/>
        <source>Lead</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9871"/>
        <source>A1: Generator turn on voltage
B1: Generator turn off voltage
A1 Setting range: [250, 900]
B1 Setting range: [250, 900]
Set rule:B1 - A1 ≥ 10V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10437"/>
        <source>Automatic operation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10451"/>
        <source>SystemInformation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10459"/>
        <source>Version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10469"/>
        <location filename="../win.ui" line="10474"/>
        <location filename="../win.ui" line="10479"/>
        <location filename="../win.ui" line="10484"/>
        <location filename="../win.ui" line="10489"/>
        <source>新建行</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10494"/>
        <location filename="../win.ui" line="10499"/>
        <source>新建列</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10504"/>
        <location filename="../win.cpp" line="4671"/>
        <source>Monitoring software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10519"/>
        <source>Protocol version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10524"/>
        <location filename="../win.cpp" line="4689"/>
        <source>Converter software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10529"/>
        <location filename="../win.cpp" line="4698"/>
        <source>CPLD software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10534"/>
        <source>SN:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10545"/>
        <source>Network</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10585"/>
        <source>              interface:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2588"/>
        <location filename="../win.ui" line="10626"/>
        <source>Port:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10695"/>
        <source>DHCP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10711"/>
        <source>STATIC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10731"/>
        <source>ip：</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10761"/>
        <source>netmask:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10794"/>
        <source>gateway:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10824"/>
        <source>Server ip:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10744"/>
        <source>192 . 168 . 1 . 100</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10777"/>
        <source>255 . 255 . 255 . 0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10807"/>
        <source>192 . 168 .  1  . 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10837"/>
        <source> 192 . 168 . 1  . 200</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10864"/>
        <location filename="../win.cpp" line="2294"/>
        <source>Apply and Restart system</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10607"/>
        <source>eth0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10648"/>
        <source>502</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10952"/>
        <source>Menu</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10993"/>
        <source>M_01 Converter turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="11028"/>
        <source>Current mode:CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1078"/>
        <source>Advance setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1170"/>
        <location filename="../win.cpp" line="3924"/>
        <source>Check</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1170"/>
        <source>StartTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1170"/>
        <source>EndTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1170"/>
        <location filename="../win.cpp" line="3927"/>
        <source>State</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1170"/>
        <source>Power(kW)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2182"/>
        <source>Display today&apos;s AC-side power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2186"/>
        <source>Display this month&apos;s AC-side power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2190"/>
        <source>Display this year&apos;s AC-side power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2194"/>
        <source>Display total AC-side power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2198"/>
        <source>Display today&apos;s AC-side power charge amount</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2202"/>
        <source>Display this month&apos;s AC-side power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2206"/>
        <source>Display this year&apos;s AC-side power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2210"/>
        <source>Display total AC-side power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2924"/>
        <source>Alarm levels uploaded from BMS, level one alarm is yellow, level two alarm is orange, and level three alarm is red;
By default, the converter does not respond to level one and level two alarms, but shuts down in response to level three alarms.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2950"/>
        <source>Inv. side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2959"/>
        <source>Inv. side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2968"/>
        <source>Inv. side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2977"/>
        <source>Inv. side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2986"/>
        <source>Inv. side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3004"/>
        <source>Active power P on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3013"/>
        <source>Reactive power Q on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3022"/>
        <source>Apparent power S on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3032"/>
        <source>Power factor PF on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3041"/>
        <source>Converter battery side voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3050"/>
        <source>Converter battery side current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3059"/>
        <source>Converter battery side power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3068"/>
        <source>Converter bus voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3077"/>
        <source>The IGBT temperature of the converter: The IGBT temperature must not exceed 102°C. Otherwise, the converter will operate at a reduced capacity. It will resume full power operation when the temperature drops to 73°C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3086"/>
        <source>”The ambient temperature.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3101"/>
        <source>Grid side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3110"/>
        <source>Grid side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3119"/>
        <source>Grid side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3128"/>
        <source>Grid side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3137"/>
        <source>Grid side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3146"/>
        <source>Grid side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3155"/>
        <source>Active power P on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3164"/>
        <source>Reactive power Q on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3173"/>
        <source>Apparent power S on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3182"/>
        <source>Frequency on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3191"/>
        <source>Power factor PF on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3206"/>
        <source>Load side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3215"/>
        <source>Load side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3224"/>
        <source>Load side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3233"/>
        <source>Load side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3242"/>
        <source>Load side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3251"/>
        <source>Load side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3260"/>
        <source>Active power P on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3269"/>
        <source>Reactive power Q on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3278"/>
        <source>Apparent power S on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3287"/>
        <source>Power factor PF on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3329"/>
        <source>The output circuit breaker has two states: On, Off. It can only be manually opened and closed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3347"/>
        <source>The power grid circuit breaker has two states: On, Off; The power grid circuit breaker can only be manually disconnected.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3365"/>
        <source>The converter has two states: Enable,Disabled. The converter is enabled when the self-check is successful. Otherwise, the converter is disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3401"/>
        <source>LVRT states : Enable , Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3410"/>
        <source>There are two states of forced charge: Enable, Disable. Turn on forced charge when enabled, and stop forced charge when disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3506"/>
        <source>Grid conected mode of the converter </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3507"/>
        <source>When &quot;Auto&quot; is selected, the converter will automatically switch between grid-on and grid-off. When the grid side is normal, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter operates in grid-off mode (VF).                                               When &quot;Grid-on&quot; is selected, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter will shut down.                                               When &quot;Grid-off&quot; is selected, the converter operates in grid-off mode (VF).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3518"/>
        <source>AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. When the advanced setting for power control mode is set to Constant Power mode (CP_AC), a positive value indicates discharging, and a negative value indicates charging.
For example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3542"/>
        <source>This item can modify the power factor, where the power factor is equal to the ratio of active power to apparent power. A positive value indicates leading reactive power, while a negative value indicates lagging reactive power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3551"/>
        <source>This parameter can change the reactive power Q, positive value indicates leading reactive power, negative value indicates lagging reactive power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3560"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant voltage and modify the voltage value. Converter will operate at the constant voltage value and function as a constant voltage source.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3569"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant current and modify the current value. Converter will charge or discharge the battery with this current value. Positive values represent discharging, while negative values represent charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3580"/>
        <source>Local: Converter control through HMI, In this mode, the EMS can only read and cannot write.
Remote: In remote mode, the EMS can perform both read and write control.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3590"/>
        <source>Device number: You can set ID number, which can be set within the range of M_01 to M_12.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3599"/>
        <source>Parallel operation: When converter operates at grid-off mode in parallel, this item needs to be enabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3722"/>
        <source>Charging SOC of Diesel Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3723"/>
        <source>Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3732"/>
        <source>Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3741"/>
        <source>Charging Stop SOC: In grid expansion mode, when the battery is charging, it will stop charging when the battery SOC is greater than this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3750"/>
        <source>Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3759"/>
        <source>Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3768"/>
        <source>Force Charge start: When the cell voltage drops below this value, the AC side will charge the battery at 10% of the machine capacity.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4364"/>
        <location filename="../win.cpp" line="4378"/>
        <location filename="../win.cpp" line="4392"/>
        <location filename="../win.cpp" line="4406"/>
        <location filename="../win.cpp" line="4420"/>
        <location filename="../win.cpp" line="4434"/>
        <location filename="../win.cpp" line="4448"/>
        <location filename="../win.cpp" line="4462"/>
        <location filename="../win.cpp" line="4476"/>
        <location filename="../win.cpp" line="4490"/>
        <source>charge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4371"/>
        <location filename="../win.cpp" line="4385"/>
        <location filename="../win.cpp" line="4399"/>
        <location filename="../win.cpp" line="4413"/>
        <location filename="../win.cpp" line="4427"/>
        <location filename="../win.cpp" line="4441"/>
        <location filename="../win.cpp" line="4455"/>
        <location filename="../win.cpp" line="4469"/>
        <location filename="../win.cpp" line="4483"/>
        <location filename="../win.cpp" line="4497"/>
        <source>discharge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2270"/>
        <source>Interface</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1978"/>
        <location filename="../win.cpp" line="1982"/>
        <location filename="../win.cpp" line="1986"/>
        <location filename="../win.cpp" line="2123"/>
        <location filename="../win.cpp" line="2182"/>
        <location filename="../win.cpp" line="2186"/>
        <location filename="../win.cpp" line="2190"/>
        <location filename="../win.cpp" line="2194"/>
        <location filename="../win.cpp" line="2198"/>
        <location filename="../win.cpp" line="2202"/>
        <location filename="../win.cpp" line="2206"/>
        <location filename="../win.cpp" line="2210"/>
        <location filename="../win.cpp" line="2214"/>
        <location filename="../win.cpp" line="2218"/>
        <location filename="../win.cpp" line="2222"/>
        <location filename="../win.cpp" line="2226"/>
        <location filename="../win.cpp" line="2230"/>
        <location filename="../win.cpp" line="2234"/>
        <location filename="../win.cpp" line="2238"/>
        <location filename="../win.cpp" line="2242"/>
        <location filename="../win.cpp" line="2246"/>
        <location filename="../win.cpp" line="2250"/>
        <location filename="../win.cpp" line="2254"/>
        <location filename="../win.cpp" line="2258"/>
        <location filename="../win.cpp" line="2271"/>
        <location filename="../win.cpp" line="2275"/>
        <location filename="../win.cpp" line="2279"/>
        <location filename="../win.cpp" line="2283"/>
        <location filename="../win.cpp" line="2287"/>
        <location filename="../win.cpp" line="2291"/>
        <location filename="../win.cpp" line="2295"/>
        <location filename="../win.cpp" line="2310"/>
        <location filename="../win.cpp" line="2314"/>
        <location filename="../win.cpp" line="2318"/>
        <location filename="../win.cpp" line="2322"/>
        <location filename="../win.cpp" line="2326"/>
        <location filename="../win.cpp" line="2330"/>
        <location filename="../win.cpp" line="2334"/>
        <location filename="../win.cpp" line="2338"/>
        <location filename="../win.cpp" line="2868"/>
        <location filename="../win.cpp" line="2872"/>
        <location filename="../win.cpp" line="2876"/>
        <location filename="../win.cpp" line="2880"/>
        <location filename="../win.cpp" line="2884"/>
        <location filename="../win.cpp" line="2888"/>
        <location filename="../win.cpp" line="2892"/>
        <location filename="../win.cpp" line="2896"/>
        <location filename="../win.cpp" line="2900"/>
        <location filename="../win.cpp" line="2904"/>
        <location filename="../win.cpp" line="2908"/>
        <location filename="../win.cpp" line="2912"/>
        <location filename="../win.cpp" line="2916"/>
        <location filename="../win.cpp" line="2920"/>
        <location filename="../win.cpp" line="2924"/>
        <location filename="../win.cpp" line="2928"/>
        <location filename="../win.cpp" line="2932"/>
        <location filename="../win.cpp" line="5869"/>
        <location filename="../win.cpp" line="5900"/>
        <location filename="../win.cpp" line="5908"/>
        <location filename="../win.cpp" line="5916"/>
        <location filename="../win.cpp" line="5924"/>
        <location filename="../win.cpp" line="6018"/>
        <source>OK</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1193"/>
        <location filename="../win.cpp" line="2949"/>
        <source>Inv. voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1193"/>
        <location filename="../win.cpp" line="2958"/>
        <source>Inv. voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1193"/>
        <location filename="../win.cpp" line="2967"/>
        <source>Inv. voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1194"/>
        <location filename="../win.cpp" line="2976"/>
        <source>Inv. current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1194"/>
        <location filename="../win.cpp" line="2985"/>
        <source>Inv. current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1194"/>
        <location filename="../win.cpp" line="2994"/>
        <source>Inv. current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1905"/>
        <location filename="../win.cpp" line="3418"/>
        <source>Start Diesel Generator Signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1906"/>
        <location filename="../win.cpp" line="3445"/>
        <source>Dry contact EPO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1907"/>
        <location filename="../win.cpp" line="3454"/>
        <source>Dry contact Shutdown</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2181"/>
        <source>Discharge Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2185"/>
        <source>Discharge Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2189"/>
        <source>Discharge Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2193"/>
        <source>Discharge Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2197"/>
        <source>Charge Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2201"/>
        <source>Charge Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2205"/>
        <source>Charge Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2209"/>
        <source>Charge Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2213"/>
        <source>Month-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2217"/>
        <source>Year-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2221"/>
        <source>Daily electricity quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2222"/>
        <source>To view the daily charge and discharge volume, click here to jump to the histogram of daily charge and discharge volume. The horizontal axis is in day, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2225"/>
        <source>Annual electricity quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2226"/>
        <source>To view the annual charge and discharge volume, click here to jump to the histogram of the annual charge and discharge volume, the horizontal axis is in year, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2229"/>
        <source>Month+</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2233"/>
        <source>Year+</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2237"/>
        <source>Monthly electric quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2238"/>
        <source>To view the monthly charge and discharge volume, click here to jump to the histogram of monthly charge and discharge volume. The horizontal axis is in month, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2241"/>
        <source>Total electric quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2242"/>
        <source>To view the total charge and discharge, click here to jump to the overview chart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2274"/>
        <location filename="../win.cpp" line="2333"/>
        <source>Port</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2278"/>
        <source>Ip</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2282"/>
        <source>Netmask</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2286"/>
        <source>Gateway</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2290"/>
        <source>Serber ip</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2295"/>
        <source>This is the application and restart the system. After clicking, the system will be restarted. If there is an upgrade of the monitoring screen program, the new monitoring screen program will be used after the restart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2393"/>
        <source>CAN communication failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2396"/>
        <source>Fire alarm (High temp. alarm)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2793"/>
        <source>Power control type：CP_P-&gt;CP_N&amp;&amp;P</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2796"/>
        <source>Power control type：CP_N&amp;&amp;P-&gt;CP_P</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2799"/>
        <source>Grid Fre Upper limit：0.2-&gt;3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2802"/>
        <source>Grid Fre Upper limit：3-&gt;0.2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2805"/>
        <source>Voltage protection Lower limit：-10-&gt;-15</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2808"/>
        <source>Voltage protection Lower limit：-15-&gt;-10</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2811"/>
        <source>Operation mode：Prevent countercurrnet-&gt;Peak valley</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2820"/>
        <source>Operation mode：UPS-&gt;Prevent countercurrnet</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2817"/>
        <source>Operation mode：Manual-&gt;UPS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1977"/>
        <source>Turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1981"/>
        <source>Stand-by</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1985"/>
        <source>Turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2309"/>
        <source>DO turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2310"/>
        <source>This is the DO control closure, provided for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2313"/>
        <source>Do turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2314"/>
        <source>This is the DO control off, provided for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2317"/>
        <source>Local on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2318"/>
        <source>This is to start a local soft boot, only for internal debugging use.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2321"/>
        <source>Local off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2322"/>
        <source>This is to turn off the local soft boot for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2814"/>
        <source>Operation mode：Peak valley-&gt;Manual</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2823"/>
        <source>Inv ON/Off-Grid：Off-&gt;automatic</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2826"/>
        <source>Inv ON/Off-Grid：automatic-&gt;Off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2867"/>
        <source>Bat volage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2883"/>
        <source>Cell voltage(max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2887"/>
        <source>Cell voltage(min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2891"/>
        <source>Cell temp.(max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2895"/>
        <source>Cell temp.(min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2923"/>
        <source>Alarm level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1307"/>
        <location filename="../win.cpp" line="3286"/>
        <source>Load power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3301"/>
        <source>DC input Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3301"/>
        <location filename="../win.cpp" line="3310"/>
        <location filename="../win.cpp" line="3319"/>
        <location filename="../win.cpp" line="3328"/>
        <location filename="../win.cpp" line="3337"/>
        <location filename="../win.cpp" line="3346"/>
        <location filename="../win.cpp" line="3355"/>
        <source>On</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3302"/>
        <source>There are two states for a DC circuit breaker: On, Off.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3311"/>
        <source>The DC contactor has two states: On, Off. After the soft start of the DC side is completed, the DC contactor closes. When the DC side of the battery is disconnected and the voltage of the DC bus drops to a certain level, the DC contactor opens.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3320"/>
        <source>The output contactor has two states: On, Off. The output contactor closes after the soft start on the inv. side is completed. The output contactor opens when the converter is shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3328"/>
        <source>Output Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3338"/>
        <source>The grid contactor has two states: On, Off. When the inverter is in grid-connected mode and the grid voltage is normal, the grid contactor is closed. When the inverter is in island mode, the grid contactor is open. In the islanded state, the grid contactor remains open.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3356"/>
        <source>There are two states for the maintenance bypass circuit breaker: On, Off. This circuit breaker is only used for machine maintenance. If maintenance is required, please contact the maintenance personnel.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3931"/>
        <source>End time: The system stops automatically running when the system reaches this time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3934"/>
        <source>Start time: When the system reaches this time, it starts to run automatically.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3935"/>
        <source>Select: After this function is enabled, the system automatically runs the selected function mode within the specified period.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5134"/>
        <source>Non
adjustable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3346"/>
        <source>Grid Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2122"/>
        <source>Alarm icon</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1195"/>
        <location filename="../win.cpp" line="3003"/>
        <source>Inv. active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1195"/>
        <location filename="../win.cpp" line="3012"/>
        <source>Inv. reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1195"/>
        <location filename="../win.cpp" line="3021"/>
        <source>Inv. apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1195"/>
        <location filename="../win.cpp" line="3031"/>
        <source>Inv. power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1386"/>
        <source>System Information</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1978"/>
        <source>The converter off switch. Click to turn off the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1982"/>
        <source>The converter standby switch. Click the converter to enter the standby state.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1986"/>
        <source>The converter on switch. Click to turn on the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2122"/>
        <source>Alarm icon: It is not displayed when there is no alarm. When there is a minor alarm, a yellow icon is displayed. When there is a fault alarm, a red icon is displayed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2214"/>
        <source>To view the data of the previous month.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2218"/>
        <source>To view the data of the previous year.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2230"/>
        <source>To view the data of the next month.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2234"/>
        <source>To view the data of the next year.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2246"/>
        <source>Export History Records, click here to export the history records to a U disk. The exported file will be named Record.csv, and it needs to be opened with Excel.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2250"/>
        <source>Export operation log. Click here to export operation log to U disk.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2254"/>
        <source>Export the battery statistics. Click here to export the battery statistics to the U disk.
The accuracy is 0.1, which means that the obtained data multiplied by 0.1 gives the actual value.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2258"/>
        <source>Eject U disk.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2326"/>
        <source>Battery power-on: This function allows the BMS to send a command to close the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2330"/>
        <source>Battery power-off: This function allows the BMS to send a command to open the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2334"/>
        <source>Select the port to be monitored. The optional port types are: None, RS485/2, RS485/3, RS485/4, RS485/5, RS485/6, CAN 1, CAN 2, Eth.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2338"/>
        <source>Start/Stop capturing messages.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2372"/>
        <source>The message data will be recorded in the root directory of the USB drive in the &apos;PortDate.txt&apos; file.
Please connect a UBS flash drive!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2388"/>
        <source>0 represents an alarm event, and this item will turn red. 1 represents a status event.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2390"/>
        <source>Event start time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2392"/>
        <source>Event end time: &apos;... &apos;indicates that there is no end time,&apos;-&apos; indicates that the event is in progress.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2394"/>
        <source>event description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2395"/>
        <source>event description.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2398"/>
        <source>Converter Standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2399"/>
        <source>The grid contactor connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2400"/>
        <source>The grid breaker connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2401"/>
        <source>The output breaker connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2402"/>
        <source>Buck not softened</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2403"/>
        <source>Contactor off buck</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2405"/>
        <source>The grid breaker disconnected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2712"/>
        <source>System settings operation records.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2868"/>
        <source>Total voltage of the battery uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2872"/>
        <source>Total current of the battery uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2876"/>
        <source>Battery SOH uploaded from BMS, the percentage of available capacity after full charge compared to the rated capacity.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2880"/>
        <source>Battery SOC uploaded by BMS refers to the current remaining battery capacity percentage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2884"/>
        <source>The highest voltage of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2888"/>
        <source>The lowest voltage of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2892"/>
        <source>The highest temperature of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2896"/>
        <source>The lowest temperature of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2900"/>
        <source>The limit of charging current uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2904"/>
        <source>The limit of discharging current uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2908"/>
        <source>The allowable charging power uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2912"/>
        <source>The allowable discharging power uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2916"/>
        <source>The allowable charging capacity uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2920"/>
        <source>The allowable discharging capacity uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2927"/>
        <source>Charging enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2928"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to charge, Disable indicates the battery is not allowed to charge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2931"/>
        <source>Discharging enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2932"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to discharge, Disable indicates the battery is not allowed to discharge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2995"/>
        <source>Inv. side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3364"/>
        <source>Disabled</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3374"/>
        <source>There are three states for DC soft start: Not starting, Soft starting, and Complete. Soft start refers to the process in which the converter charges the busbar with the battery during startup, causing the busbar voltage to rise close to the battery voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3383"/>
        <source>Converter states include: OFF, AC Soft Start, Grid-ON Charge, Grid-ON Discharge, Grid-OFF Discharge, Derating grid-on, Standby, Grid-OFF Charge, Constant Voltage Discharge and Constant Voltage Charge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3392"/>
        <source>There are three types of reactive power regulation: Disable,PF regulation, and  regulation.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3419"/>
        <source>Signal to start the diesel generator, start the diesel generator when enabled, stop the diesel generator when disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3428"/>
        <source>Dry contact 2 is output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3437"/>
        <source>Dry contact 3 is output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3446"/>
        <source>Dry contact EPO：Enable，Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3455"/>
        <source>Dry contact Shutdown：Enable，Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3463"/>
        <source>Access signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3464"/>
        <source>Access signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3473"/>
        <source>Full power signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3482"/>
        <source>Smoke alarm signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3777"/>
        <source>Force Charge stop: When the cell voltage exceeds this value, the converter exits the forced charging and returns to the state before forced charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4774"/>
        <source>Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol. Currently supported battery manufacturer protocols include:MEGA, LISHEN, GREATPOWER, GOLD, BMSER, LANLI, SLANPOWER, PYLON, CATL, SUOYING, SUNWODA, CUBENERGY, GOLD_V2, TOPGOLD, PGS, WOBOYUAN, KGOOER, HZLDE, PYLON_L, VILION, ALPHA, TUOPU, JIEHUI, JDI, SCU, FARO, BGS, JDITEC, HUASU, LIGOO, FDBatt, FREEDOM, CATL_RTU.                                             
Select AUTO to automatically detect the battery manufacturer protocol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4990"/>
        <source>Upper limit of power grid frequency variation range: The maximum range of frequency variation allowed on the AC side, which can be selected as 0.2, 0.5, 1, 5.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5135"/>
        <source>Reactive Power Output Mode: Default non-adjustable, options include non-adjustable, Power Factor, Reactive Power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5143"/>
        <source>Non
Countercurrent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5144"/>
        <source>Converter Anti-Reverse Flow: Countercurrent,
Non Countercurrent;
Countercurrent allows converter current to flow into the grid, while Non Countercurrent prevents converter current from flowing into the grid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5411"/>
        <source>DI_1_Function</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5419"/>
        <source>DI_2_Function</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5427"/>
        <source>DI_3_Function</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5435"/>
        <source>DI_4_Function</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5443"/>
        <source>DI_5_Function</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5451"/>
        <source>DI_6_Function</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5900"/>
        <source>Display the current status of the DCAC converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5908"/>
        <source>Current Mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5908"/>
        <source>Display the current control power mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5993"/>
        <source>Make sure to press the EPO button before upgrading.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1908"/>
        <location filename="../win.cpp" line="3490"/>
        <source>Fire fighting signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3491"/>
        <source>Fire fighting signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3506"/>
        <source>automatic</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3589"/>
        <source>M_01</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3614"/>
        <source>Grid-on DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3615"/>
        <source>Grid-on DOD, allowable depth of discharge in grid-on mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3623"/>
        <source>Grid-off DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3624"/>
        <source>Grid-off DOD, allowable depth of discharge in grid-off mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3632"/>
        <source>Charge Volt upper Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3633"/>
        <source>Charging voltage upper limit: When the battery total voltage reaches this value during charging, the converter will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3642"/>
        <source>Charging voltage upper limit hysteresis: When the battery is charging, if the battery total voltage reaches the charging voltage upper limit, the converter will shut down. When the battery total voltage drops below the charging voltage upper limit minus the hysteresis value, the converter will automatically turn on.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3650"/>
        <source>Discharge Volt lower Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3651"/>
        <source>Discharge voltage lower limit: When the battery total voltage reaches this value during discharge, the converter will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3660"/>
        <source>Discharge voltage lower limit hysteresis: When the battery is discharging, if the battery total voltage drops below the discharge voltage lower limit, the converter will shut down. When the battery total voltage exceeds the discharge voltage lower limit plus the hysteresis value, the converter will automatically turn on.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3668"/>
        <source>Charge Current Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3669"/>
        <source>Charging current limit: The maximum allowable current on the battery side to prevent overcurrent during charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3677"/>
        <source>Discharge Current Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3678"/>
        <source>Discharging current limit: The maximum allowable current on the battery side to prevent overcurrent during Discharging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3705"/>
        <source>When the specified SOC is reached, the diesel generator shuts down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3713"/>
        <source>Genertor turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3714"/>
        <source>When the specified SOC is reached, the diesel generator starts.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3788"/>
        <source>Start SOC: In UPS mode, when the battery SOC reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3797"/>
        <source>Stop SOC: In UPS mode, when the battery SOC reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3806"/>
        <source>Start cell voltage: In UPS mode, when the lowest voltage of a battery cell reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3815"/>
        <source>Stop cell voltage: In UPS mode, when the highest voltage of a battery cell reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3824"/>
        <source>Start total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3833"/>
        <source>Stop total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3842"/>
        <source>Backup charging power: In UPS mode, the backup charging power of the converter when the battery starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3851"/>
        <source>Monthly cycling date: On the same day of each month, a deep discharge and recharge will be performed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3865"/>
        <source>The number of battery cells connected in series in the battery stack (based on a 2V unit).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3880"/>
        <source>Charging Current Limit: The maximum allowable current on the battery side to prevent overcurrent during charging. (Upper limit: 0.25C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3885"/>
        <source>Discharge Current Limit: The maximum allowable current on the battery side to prevent overcurrent during discharge. (Upper limit: 0.5C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3890"/>
        <source>Generator Shutdown Voltage: When the specified voltage is reached, the diesel generator will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3895"/>
        <source>Generator Start Voltage: When the specified voltage is reached, the diesel generator will start up.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3899"/>
        <source>Grid-off EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3900"/>
        <source>Grid-off discharge cut-off voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3904"/>
        <source>Grid-on EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3905"/>
        <source>Grid-on discharge cut-off voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3910"/>
        <source>Uniform charging to flushing current: Upper limit of 0.025C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3915"/>
        <source>Float turn to uniform charging current: Upper limit of 0.15C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3932"/>
        <source>This working state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3933"/>
        <source>Working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4723"/>
        <source>Battery Types: Lithium, Lead-Acid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4732"/>
        <source>Battery Communication Modes: None, RS485, CAN, Ethernet, EMS Dispatch.
EMS Dispatch: Select this option when uploading battery data from EMS (EMS_CAN). If MEGA standard CAN_BMS_EMS protocol is used, EMS_CAN protocol needs to select &quot;standard&quot;.
(Note: Due to the fact that CAN and Ethernet both have only one port, the battery communication mode and EMS communication mode cannot be selected as &quot;CAN&quot; or &quot;Ethernet&quot; simultaneously.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4743"/>
        <source>Constant Voltage (CV) mode: The converter will operate in constant voltage mode on the DC side.                                              Constant Current (CC) mode: The converter will operate in constant current mode on the DC side.                                              Constant Power AC (CP_AC) mode: The power level can be set at &quot;constant power.&quot; The value represents the power level, positive for discharge and negative for charge. For example, setting it to -5 means that the AC side will charge the battery with a power of 5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Conversely, setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.                                              Reserved.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4755"/>
        <source>EMS communication methods: RS485, CAN, Ethernet.                                         The setting communication methods are readable and writable in remote mode, and only readable in local mode. The unselected communication methods are only readable in both remote and local mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4765"/>
        <source>Output Power Limit: Restricts the upper limit of the set value for the power on the AC side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="709"/>
        <location filename="../win.cpp" line="4793"/>
        <source>Anti-backflow power tolerance</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4794"/>
        <source>Anti-backflow power tolerance.The default power tolerance is 10 kW. When the output power increases to &quot;output power limit + power tolerance&quot;, the output power will be reduced to &quot;output power limit - power tolerance&quot;.
(Note: This setting only takes effect in the system anti-backflow mode and is used to control the power tolerance at the grid entrance).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="392"/>
        <location filename="../win.cpp" line="4804"/>
        <source>Serial Communication Address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4805"/>
        <source>Serial Communication Address: The default value is 1, adjustable range is between 1 and 255, used for matching address during serial communication.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4824"/>
        <source>Serial Port 2 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 2 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4833"/>
        <source>Serial Port 3 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 3 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4843"/>
        <source>Serial Port 4 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 4 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4852"/>
        <source>Serial Port 5 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 5 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="672"/>
        <location filename="../win.cpp" line="4860"/>
        <source>serial port 6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4861"/>
        <source>Serial Port 6 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 6 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4870"/>
        <source>CAN1 Port: The baud rate for internal communication is 500 kbps by default and cannot be modified. </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4879"/>
        <source>CAN2 Port: Optional baud rates for the CAN2 port include 100, 125, 250, 500, and 800 kbps, with a default baud rate of 500 kbps.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4888"/>
        <source>Protocol version: View the current protocol version. The default protocol version number is V1.0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4897"/>
        <source>User password: Available for resetting the user password. The default user password is 123456. (Note: The user password must be six digits.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="504"/>
        <location filename="../win.cpp" line="4905"/>
        <source>Admin password</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4906"/>
        <source>Admin password: Available for resetting the admin password. The default admin password is 888888. (Note: The admin password must be six digits.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="963"/>
        <location filename="../win.cpp" line="4980"/>
        <source>Power change rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4981"/>
        <source>Power change rate: the rate at which power changes within a second .</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4999"/>
        <source>Lower limit of power grid frequency variation range: The maximum range of frequency variation allowed on the AC side, which can be selected as-0.5, -1, -2, -5.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5008"/>
        <source>Upper limit of voltage protection range: The maximum range of voltage variation allowed on the AC side, which can be selected as 10, 15, 20.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5017"/>
        <source>Lower limit of voltage protection range: The minimum range of voltage variation allowed on the AC side, which can be selected as -10, -15, -20.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5026"/>
        <source>High voltage ride through(HVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5035"/>
        <source>Low voltage ride through(LVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5044"/>
        <source>Prevent islanding effect. When islanding effect is detected (in a photovoltaic grid-on system, when a power outage occurs in the main grid, and the PV grid-connected converter generates power that matches the local load on the low-voltage side of the grid, it can easily sustain power generation independently, resulting in an &apos;island&apos; phenomenon, which endangers the safety of maintenance personnel), the converter automatically shuts down. The options for this feature can be set as &apos;Enable&apos; or &apos;prohibited&apos; .(Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5054"/>
        <source>Insulation detection enable, the insulation resistance should be greater than 33KΩ for normal start-up and operation. If it is less than 33KΩ, it should not start, and an alarm should be triggered. By default, it is disabled, but can be set as &apos;Enable&apos; or &apos;prohibited&apos;.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5063"/>
        <source>Primary frequency control enable: When the grid frequency deviates from the rated value, the active power is controlled to increase or decrease in order to maintain the grid frequency at the rated value. It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5072"/>
        <source>Rotational inertia enable: It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5081"/>
        <source>Constant voltage parallel operation enable: It can be selected as enabled or disabled.  (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5090"/>
        <source>Converter Model: As per factory settings, generally not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5099"/>
        <source>The rated capacity of the converter shall be based on the factory value and cannot be changed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5108"/>
        <source>Output Frequency Level: Default 50Hz, typically 50Hz or 60Hz.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5117"/>
        <source>Output Voltage Level: As per factory settings, generally not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5126"/>
        <source>Transformer Voltage Ratio: To be determined by the factory nameplate, not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1266"/>
        <location filename="../win.cpp" line="5143"/>
        <source>Converter Anti-Reverse Flow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5156"/>
        <source>System Anti-Reverse Flow: Enable, Disable;
Enabling prevents system current from flowing into the grid, while Disabling allows system current to flow into the grid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5166"/>
        <source>Frequency Deviation Deadzone: A frequency difference settings to prevent unnecessary frequency regulation actions during minor grid frequency fluctuations. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5175"/>
        <source>Active Frequency Regulation Coefficient: The active frequency regulation coefficient can be configured. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5193"/>
        <source>DynamicCap: Enable, Disable.
This is the dynamic capacity expansion function done by DSP: the capacity of the power grid port is set by constant power, the positive value is the grid capacity attribute, and the negative value is the load capacity attribute, which can be dispatched by EMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5220"/>
        <source>Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5249"/>
        <source>When the dry contact is enabled, the device will perform the selected action when there is a change in the signal.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5250"/>
        <source>Input Dry Contact:                       
Enabled: Triggers the Action when the dry contact detects a state other than the specified NO/NC.                      
Disabled: No action is taken when the dry contact detects a state other than the specified NO/NC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5253"/>
        <source>The dry contact function is optional.
Optional function items: EPO Shut Down, Shut Down NC, Access Control, Full power, Smoke, Temperature, Water logging, BMS alarm, ATS signal.
For example, the function item of DI3 will select &quot;Access Control&quot; and will prompt an access control alarm when the signal is triggered.Similarly, the function item of DI3 will select &quot;Smoke&quot; and will prompt a smoke alarm when the signal is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5264"/>
        <source>DI 1 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5272"/>
        <source>DI 2 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5280"/>
        <source>DI 3 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5288"/>
        <source>DI 4 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5296"/>
        <source>DI 5 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5304"/>
        <source>DI 6 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5466"/>
        <source>DOD protection: Actions to be performed when DOD protection is triggered. The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5475"/>
        <source>The action performed when the charge ban is triggered;Optional function: NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5484"/>
        <source>The action to be performed when a ban is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5492"/>
        <source>level 1 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5501"/>
        <source>level 2 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5510"/>
        <source>level 3 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5519"/>
        <source>level 1 alarm CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5520"/>
        <source>The charging power executed when a level 1 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5528"/>
        <source>level 2 alarm CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5529"/>
        <source>The charging power executed when a level 2 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5546"/>
        <source>level 1 alarm DP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5547"/>
        <source>The discharging power executed when a level 1 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5556"/>
        <source>The discharging power executed when a level 2 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5992"/>
        <source>Upgrade prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5993"/>
        <source>NEXT</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5993"/>
        <source>Cancel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="6014"/>
        <source>Working mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="6015"/>
        <source>When selecting the manual mode, the converter’s operating status, charging or discharging power (active power), reactive power, power factor etc,can be controlled through HMI or EMS.                              When selecting the UPS mode, When the grid side is abnormal, the system will switch from zero power to grid-off discharge mode to provide energy to critical loads. Please go to the &quot;Battery Settings&quot; page to configure this mode. Note: This mode is only applicable to lithium battery mode and requires normal communication between the converter and BMS.                              Peak shaving and valley filling mode is used for peak-valley price arbitrage. The converter can operate according to the local peak-valley electricity price periods. Please set the operating time period, charging or discharging mode, charging or discharging power, and other information on the &quot;Mixed mode&quot; page.
Grid expansion.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="6018"/>
        <source>Click to view grid expansion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3517"/>
        <source>Constant power(AC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3523"/>
        <source>Manual</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3758"/>
        <source>Grid_capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3787"/>
        <source>Turn_on_SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3796"/>
        <source>Turn_off_SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3805"/>
        <source>Turn_on_cell_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3814"/>
        <source>Turn_off_cell_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3823"/>
        <source>Turn_on_total_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3832"/>
        <source>Turn_off_total_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3841"/>
        <source>UPS_charge_power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3850"/>
        <source>Monthly_cycle_time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3860"/>
        <source>Capacity, the capacity of the lead-acid battery.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3864"/>
        <source>Cell_number_2V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3870"/>
        <source>This is the floating charge voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3875"/>
        <source>This is the filling voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3925"/>
        <source>Start_Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3926"/>
        <source>End_Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3928"/>
        <source>Power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3929"/>
        <source>9:00</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3930"/>
        <source>10:00</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4672"/>
        <source>This is the monitoring version number.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4785"/>
        <source>EMS CAN Protocol: NONE, Standard(CAN_BMS_EMS protocol), DEC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4814"/>
        <source>Modbus Offset Address: The offset of the register read or write address, the default value is 0.
(For example, Modbus protocol has a 1050 register (output line voltage AB), when the Modbus offset address is 3000, the register address used to read its value is 4050.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4946"/>
        <source>Energy meter model: The energy meter model is selected according to the type of energy meter that is connected. According to the characteristics and specifications of the connected watt-hour meter, select the corresponding watt-hour meter model, which can be selected NONE, DTSD1352, AMC96-E4/KC or ADL3000-E-B.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10298"/>
        <location filename="../win.cpp" line="3889"/>
        <source>Generator turn off voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10362"/>
        <location filename="../win.cpp" line="3894"/>
        <source>Generator turn on voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="408"/>
        <location filename="../win.cpp" line="4680"/>
        <source>Protocol Version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4681"/>
        <source>This is the protocol version number.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4690"/>
        <source>This is the converter software version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4699"/>
        <source>This is the CPLD software version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4707"/>
        <source>SN</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4708"/>
        <source>This is SN, the serial number of the product.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9192"/>
        <location filename="../win.cpp" line="4722"/>
        <source>Lithium</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4731"/>
        <source>BMS Comm type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4754"/>
        <source>EMS Comm type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4773"/>
        <source>Auto</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="616"/>
        <location filename="../win.cpp" line="4773"/>
        <source>BAT protocol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3687"/>
        <source>Set the charging power limit to allow the maximum power of charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3696"/>
        <source>The discharge power limit is set to allow the maximum power of the discharge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3641"/>
        <source>Charge Vol upper Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3659"/>
        <source>Discharge Vol lower Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4914"/>
        <source>English</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4915"/>
        <source>Set the display language of the display screen, which can be selected as Chinese and English. The system will restart when switching languages.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4928"/>
        <source>upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4936"/>
        <source>Allow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4937"/>
        <source>Set whether the display is enabled sound, which can be allowed(Allow) or prohibited(forbid).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4784"/>
        <location filename="../win.cpp" line="4945"/>
        <source>NONE</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4954"/>
        <source>20</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4954"/>
        <source>Bms Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4955"/>
        <source>BMS communication fault determination time: The BMS communication fault determination time refers to the BMS communication fault when the BMS communication is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4963"/>
        <source>EMS Com. Fault Model</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4964"/>
        <source>EMS communication fault determination time: The EMS communication fault determination time refers to the time when the communication between the EMS is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1122"/>
        <location filename="../win.cpp" line="5007"/>
        <source>Vol protection upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1170"/>
        <location filename="../win.cpp" line="5016"/>
        <source>Vol protection lower limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5025"/>
        <location filename="../win.cpp" line="5034"/>
        <location filename="../win.cpp" line="5043"/>
        <location filename="../win.cpp" line="5053"/>
        <location filename="../win.cpp" line="5062"/>
        <location filename="../win.cpp" line="5071"/>
        <location filename="../win.cpp" line="5080"/>
        <location filename="../win.cpp" line="5192"/>
        <source>prohibit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5107"/>
        <source>Output Fre grade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5116"/>
        <source>Output vol level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5184"/>
        <source>Grid restoration time: reserved function, setting invalid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5203"/>
        <source>Number of modules for PCS, default 1(invalid setting).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5211"/>
        <source>restore</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5212"/>
        <source>Restore the factory default Settings.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5220"/>
        <source>Backup Set Parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5221"/>
        <source>Backup setting parameters: Backup setting parameters refers to backing up the parameters set on the current device so that the backup parameter Settings can be restored when needed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5229"/>
        <source>Restore Backup Set Parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5229"/>
        <source>Restore
Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5230"/>
        <source>Restore backup setting parameters: Restore backup setting parameters means to restore the device to the last backup setting parameters and restart the device.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5238"/>
        <source>Clear</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5239"/>
        <source>Clear previous recorded data and operation data of the system.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5248"/>
        <source>Normally closed circuit (NC) or normally open circuit (NO) according to field Settings.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5313"/>
        <source>DI_1_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5321"/>
        <source>DI_2_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5329"/>
        <source>DI_3_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5337"/>
        <source>DI_4_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5345"/>
        <source>DI_5_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5353"/>
        <source>DI_6_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5362"/>
        <source>DI_1_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1653"/>
        <location filename="../win.ui" line="1697"/>
        <location filename="../win.ui" line="1741"/>
        <location filename="../win.cpp" line="5370"/>
        <location filename="../win.cpp" line="5378"/>
        <location filename="../win.cpp" line="5386"/>
        <source>Prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5370"/>
        <source>DI_2_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5378"/>
        <source>DI_3_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5386"/>
        <source>DI_4_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5394"/>
        <source>DI_5_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5402"/>
        <source>DI_6_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5465"/>
        <location filename="../win.cpp" line="5474"/>
        <location filename="../win.cpp" line="5483"/>
        <location filename="../win.cpp" line="5501"/>
        <source>Standby</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5492"/>
        <source>NO action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5493"/>
        <source>Action to be performed when level 1 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5502"/>
        <source>Action to be performed when level 2 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5511"/>
        <source>Action that is performed when level 3 alarm is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5555"/>
        <source>level 2 alarm DP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5574"/>
        <source>It is used for internal debugging only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5605"/>
        <source>Debug variable 1 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5613"/>
        <source>Debug variable 2 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5621"/>
        <source>Debug variable 3 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5629"/>
        <source>Debug memery var 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5637"/>
        <source>Debug memery var 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5645"/>
        <source>Debug memery var 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5653"/>
        <source>Input Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5661"/>
        <source>Input Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5669"/>
        <source>1.5 Voltage revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5677"/>
        <source>Bus Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5685"/>
        <source>Grid A AB Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5693"/>
        <source>Grid B BC Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5701"/>
        <source>Grid C CA Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5709"/>
        <source>Output A Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5717"/>
        <source>Output B Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5725"/>
        <source>Output C Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5733"/>
        <source>INV A Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5741"/>
        <source>INV B Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5749"/>
        <source>INV C Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5757"/>
        <source>INV A ind Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5765"/>
        <source>INV B ind Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5773"/>
        <source>INV_C_ind_Cur_revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5869"/>
        <source>static</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5869"/>
        <source>If this parameter is selected, static IP addresses are used.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5916"/>
        <source>Call in test data (for internal testing personnel only).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5924"/>
        <source>Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5924"/>
        <source>Click here to modify the time displayed on the HMI.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3579"/>
        <source>Local</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3598"/>
        <source>Parallel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5217"/>
        <location filename="../win.cpp" line="3355"/>
        <source>Maintenance Bypass Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3373"/>
        <source>Not starting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3382"/>
        <location filename="../win.cpp" line="5362"/>
        <location filename="../win.cpp" line="5394"/>
        <location filename="../win.cpp" line="5402"/>
        <location filename="../win.cpp" line="5510"/>
        <source>Shut down</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3391"/>
        <source>Reactive Power Regulation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1631"/>
        <location filename="../win.ui" line="1675"/>
        <location filename="../win.ui" line="1719"/>
        <location filename="../win.cpp" line="3418"/>
        <location filename="../win.cpp" line="5264"/>
        <location filename="../win.cpp" line="5280"/>
        <location filename="../win.cpp" line="5288"/>
        <location filename="../win.cpp" line="5296"/>
        <location filename="../win.cpp" line="5304"/>
        <source>Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4523"/>
        <source>PCS voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4533"/>
        <source>PCS voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4543"/>
        <source>PCS voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4553"/>
        <source>PCS current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4563"/>
        <source>PCS current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4573"/>
        <source>PCS current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4583"/>
        <source>PCS Active P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4588"/>
        <source>PCS Reactive P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4593"/>
        <source>PCS Parent P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4598"/>
        <source>PCS Pf</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4528"/>
        <location filename="../win.cpp" line="1197"/>
        <location filename="../win.cpp" line="3040"/>
        <source>Battery voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4538"/>
        <location filename="../win.cpp" line="1197"/>
        <location filename="../win.cpp" line="3049"/>
        <source>Battery current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4548"/>
        <location filename="../win.cpp" line="1197"/>
        <location filename="../win.cpp" line="3058"/>
        <source>Battery power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4558"/>
        <location filename="../win.cpp" line="1198"/>
        <location filename="../win.cpp" line="3067"/>
        <source>Bus voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4568"/>
        <location filename="../win.cpp" line="1198"/>
        <location filename="../win.cpp" line="3076"/>
        <source>IGBT temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4578"/>
        <location filename="../win.cpp" line="1199"/>
        <location filename="../win.cpp" line="3085"/>
        <source>Environment temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1255"/>
        <location filename="../win.cpp" line="3100"/>
        <source>Grid voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1255"/>
        <location filename="../win.cpp" line="3109"/>
        <source>Grid voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1255"/>
        <location filename="../win.cpp" line="3118"/>
        <source>Grid voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1256"/>
        <location filename="../win.cpp" line="3127"/>
        <source>Grid current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1256"/>
        <location filename="../win.cpp" line="3136"/>
        <source>Grid current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1256"/>
        <location filename="../win.cpp" line="3145"/>
        <source>Grid current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1257"/>
        <location filename="../win.cpp" line="3154"/>
        <source>Grid active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1257"/>
        <location filename="../win.cpp" line="3163"/>
        <source>Grid reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1258"/>
        <location filename="../win.cpp" line="3172"/>
        <source>Grid apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1258"/>
        <location filename="../win.cpp" line="3181"/>
        <source>Grid frequency</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1258"/>
        <location filename="../win.cpp" line="3190"/>
        <source>Grid power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1304"/>
        <location filename="../win.cpp" line="3205"/>
        <source>Load voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1304"/>
        <location filename="../win.cpp" line="3214"/>
        <source>Load voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1304"/>
        <location filename="../win.cpp" line="3223"/>
        <source>Load voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1305"/>
        <location filename="../win.cpp" line="3232"/>
        <source>Load current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1305"/>
        <location filename="../win.cpp" line="3241"/>
        <source>Load current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1305"/>
        <location filename="../win.cpp" line="3250"/>
        <source>Load current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1306"/>
        <location filename="../win.cpp" line="3259"/>
        <source>Load active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1306"/>
        <location filename="../win.cpp" line="3268"/>
        <source>Load reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1307"/>
        <location filename="../win.cpp" line="3277"/>
        <source>Load apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1895"/>
        <location filename="../win.cpp" line="1899"/>
        <source>Maintenance Bypass breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1907"/>
        <source>Access control signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1908"/>
        <location filename="../win.cpp" line="3472"/>
        <source>Full power signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1908"/>
        <location filename="../win.cpp" line="3481"/>
        <source>Smoke alarm signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2271"/>
        <source>This is the interface number, which defaults to eth0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2275"/>
        <source>This is the port number, which defaults to 502 and can be changed as needed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2279"/>
        <source>This is the IP address. The default is 192.168.1.100.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2283"/>
        <source>This is the subnet mask, 255.255.255.0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2287"/>
        <source>This is the gateway. The default is 192.168.1.1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2291"/>
        <source>This is the server IP address. The default is 192.168.1.200.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1091"/>
        <location filename="../win.cpp" line="2387"/>
        <source>Level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1091"/>
        <location filename="../win.cpp" line="2389"/>
        <source>Start Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1091"/>
        <location filename="../win.cpp" line="2391"/>
        <source>End Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9163"/>
        <location filename="../win.cpp" line="1091"/>
        <source>Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1129"/>
        <location filename="../win.cpp" line="2709"/>
        <source>ModificationTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1129"/>
        <location filename="../win.cpp" line="2711"/>
        <source>RecordEvent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2397"/>
        <source>Power Meter Comm fualttLead-acid abnormal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2710"/>
        <source>Time when the system Settings are modified.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5886"/>
        <location filename="../win.ui" line="5910"/>
        <location filename="../win.ui" line="5934"/>
        <location filename="../win.ui" line="5958"/>
        <location filename="../win.ui" line="5982"/>
        <location filename="../win.ui" line="6006"/>
        <location filename="../win.ui" line="6030"/>
        <location filename="../win.ui" line="6054"/>
        <location filename="../win.ui" line="6622"/>
        <location filename="../win.ui" line="6646"/>
        <location filename="../win.ui" line="6670"/>
        <location filename="../win.ui" line="6694"/>
        <location filename="../win.ui" line="6718"/>
        <location filename="../win.ui" line="6742"/>
        <location filename="../win.ui" line="10075"/>
        <location filename="../win.ui" line="10136"/>
        <location filename="../win.ui" line="10206"/>
        <location filename="../win.ui" line="10270"/>
        <location filename="../win.ui" line="10334"/>
        <location filename="../win.cpp" line="2386"/>
        <location filename="../win.cpp" line="3517"/>
        <source>0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1745"/>
        <source>Change Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1753"/>
        <source>切换语言</source>
        <translation>Change Language</translation>
    </message>
</context>
<context>
    <name>Menu</name>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="20"/>
        <source>Form</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="50"/>
        <source>Host</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="81"/>
        <source>Rt.Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="116"/>
        <source>Record</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="153"/>
        <source>System</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="193"/>
        <source>Turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="224"/>
        <source>Stand-by</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="255"/>
        <source>Turn off</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>Specification</name>
    <message>
        <location filename="../Specification/Specification.cpp" line="36"/>
        <source>OK</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>UpgradeTools</name>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="14"/>
        <source>UpgradeTools</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="43"/>
        <source>MPS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="66"/>
        <source>MPS Upgrade app V2.0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="102"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="502"/>
        <source> Message:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="132"/>
        <source> Mounting finished 
 File checked ok 
 Monitor Upadate file not exited 
 DCAC Upadate file ready 
 DCDC Upadate file not exited 
 Start copying...

 DCAC_Update.hex 
 UPDATE_BEGIN 
 Unknown signal received 
 Unknown signal received 
 Unknown signal received 
 ERASE GOING 
 ERASE GOING 
 BLOCK_DATATRANS_END
 BLOCK_CHECKSUM_OK 
 BLOCK_CHECKSUM_OK
 BLOCK_HEAD_OK
 BLOCK_CHECKSUM_OK
 BLOCK_DATATRANS_END
 BLOCK_HEAD_OK 
</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="174"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="438"/>
        <source>Module number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="230"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="58"/>
        <source>DCDC Upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="251"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="63"/>
        <source>DCAC Upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="274"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="661"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="68"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="91"/>
        <source>Monitor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="295"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="682"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="72"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="95"/>
        <source>Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="316"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="703"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="76"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="99"/>
        <source>Restore</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="339"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="81"/>
        <source>Apply and restart</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="391"/>
        <source>PCS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="414"/>
        <source>PCS Upgrade Tools V2.0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="532"/>
        <source> Mounting finished 
 File checked ok 
 Monitor.hex not exited
 DSPUpadate ok
 Start copying...
 
 DSPUpdate.hex
 UPDATE_BEGIN</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="566"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="115"/>
        <source>Monitor.hex</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="587"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="119"/>
        <source>DSPUpdate.hex</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="612"/>
        <source>Baud rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="636"/>
        <source>500k</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="726"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="103"/>
        <source>DSP Upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="747"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="109"/>
        <source>Restart</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="60"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="65"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="69"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="73"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="77"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="82"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="88"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="92"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="96"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="100"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="105"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="110"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="116"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="120"/>
        <source>OK</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="59"/>
        <source>DCDC Upgrade: Insert a u disk and check for the presence of the DCDC upgrade program &apos;DCDC_Update.hex&apos;. Click on DCDC, and then upgrade the corresponding DCDC module according to the selected module number above.                                
(Note: Before upgrading the DCDC, ensure that the ship mode switch on the DCDC module is set to the OFF position.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="64"/>
        <source>DCAC Upgrade: Insert the u disk and check if there is a DCAC upgrade program called &apos;DCAC_Update.hex&apos;. Click to upgrade the DCAC.                                
(Note: Press the EPO button before upgrading.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="69"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="92"/>
        <source>After inserting the u disk and checking that there is a Monitor upgrade program &apos;Monitor.hex&apos;, click to upgrade the monitor program.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="73"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="96"/>
        <source>Backup: Click to backup the current program files.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="77"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="100"/>
        <source>Restore: Restore to the most recent backup program files.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="82"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="110"/>
        <source>Click to restart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="87"/>
        <source>Baud Rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="88"/>
        <source>Baud Rate: Default is 500k and cannot be modified.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="104"/>
        <source>DSP Upgrade: Insert the u disk and check if there is a DSP upgrade program called &apos;DSPUpdate.hex&apos;. Click to upgrade the DSP.                                
(Note: Press the EPO button before upgrading.))</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="116"/>
        <source>This is the name of the monitoring upgrade program.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="120"/>
        <source>This is the DSP upgrade program name.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
