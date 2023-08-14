<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="en">
<context>
    <name>FaultTableInterface</name>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="14"/>
        <source>MainWindow</source>
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
        <source>Change
Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="71"/>
        <source>DCAC Fault Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="85"/>
        <source>DCDC Module Fault Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="95"/>
        <source>Battery Protection Logic Explanation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.ui" line="103"/>
        <source>Battery Cut-off Voltage Protection Logic Explanation for Grid-on and grid-off modes:

Grid-on mode:
  When the battery discharges to the cut-off voltage minus 5V (e.g., if the cut-off voltage is 500V, discharge stops at 495V), an alarm &quot;Discharge Not Allowed&quot; will be triggered, and the DCAC converter output power will drop to 0.
  The &quot;Discharge Not Allowed&quot; alarm will be cleared when the battery voltage is greater than the discharge cut-off voltage plus the discharge hysteresis voltage or when the mode is changed to charging.
  When the battery is charged to the upper limit of the charging voltage, an alarm &quot;Charging Not Allowed&quot; will be triggered. If the DCAC is in charging mode, the charging power will drop to 0. If the DCAC is in discharge mode, it will not be affected.
  The &quot;Charging Not Allowed&quot; alarm will be cleared when the battery voltage is lower than the upper limit of the charging voltage minus the charging hysteresis voltage or when it is in discharge mode.

Grid-off mode:
  When the battery discharges to the cut-off voltage minus 5V (e.g., if the cut-off voltage is 500V, discharge stops at 495V), an alarm &quot;Discharge Not Allowed&quot; will be triggered, and the DCAC converter will shut down. The &quot;Discharge Not Allowed&quot; alarm will be cleared when the battery voltage is greater than the discharge cut-off voltage plus the discharge hysteresis voltage. If there is no shutdown command, the system will resume operation.
  When the battery is charged to the upper limit of the charging voltage, an alarm &quot;Charging Not Allowed&quot; will be triggered. If the DCAC is in charging mode or in grid-off discharge mode, it will not be affected.
  The &quot;Charging Not All</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="53"/>
        <source>Alarm name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="53"/>
        <source>Alarm leve</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="53"/>
        <source>Trigger condition</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="54"/>
        <source>Response action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../FaultTableInterface/faulttableinterface.cpp" line="54"/>
        <source>Whether to reset
automatically and reset time</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>GridExpansion</name>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="14"/>
        <source>MainWindow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="37"/>
        <source>Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../GridExpansion/gridexpansion.ui" line="51"/>
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
        <location filename="../win.ui" line="2403"/>
        <location filename="../win.ui" line="2524"/>
        <source>Change
Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="117"/>
        <source>Basic settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="167"/>
        <source>Function Setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="219"/>
        <location filename="../win.ui" line="269"/>
        <location filename="../win.ui" line="787"/>
        <location filename="../win.ui" line="847"/>
        <location filename="../win.ui" line="1910"/>
        <location filename="../win.ui" line="1970"/>
        <location filename="../win.ui" line="3856"/>
        <location filename="../win.ui" line="4044"/>
        <location filename="../win.ui" line="4089"/>
        <location filename="../win.ui" line="4137"/>
        <location filename="../win.ui" line="4187"/>
        <location filename="../win.ui" line="4471"/>
        <location filename="../win.ui" line="4516"/>
        <location filename="../win.ui" line="7963"/>
        <location filename="../win.ui" line="8003"/>
        <location filename="../win.ui" line="8526"/>
        <location filename="../win.ui" line="8611"/>
        <location filename="../win.cpp" line="2373"/>
        <location filename="../win.cpp" line="3355"/>
        <location filename="../win.cpp" line="3364"/>
        <source>1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="224"/>
        <location filename="../win.ui" line="274"/>
        <location filename="../win.ui" line="792"/>
        <location filename="../win.ui" line="852"/>
        <location filename="../win.ui" line="1915"/>
        <location filename="../win.ui" line="1975"/>
        <location filename="../win.ui" line="3861"/>
        <location filename="../win.ui" line="4049"/>
        <location filename="../win.ui" line="4094"/>
        <location filename="../win.ui" line="4142"/>
        <location filename="../win.ui" line="4192"/>
        <location filename="../win.ui" line="4476"/>
        <location filename="../win.ui" line="4521"/>
        <location filename="../win.ui" line="7968"/>
        <location filename="../win.ui" line="8011"/>
        <location filename="../win.ui" line="8531"/>
        <location filename="../win.ui" line="8616"/>
        <source>2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="229"/>
        <location filename="../win.ui" line="279"/>
        <location filename="../win.ui" line="797"/>
        <location filename="../win.ui" line="857"/>
        <location filename="../win.ui" line="1920"/>
        <location filename="../win.ui" line="1980"/>
        <location filename="../win.ui" line="3866"/>
        <location filename="../win.ui" line="4054"/>
        <location filename="../win.ui" line="4147"/>
        <location filename="../win.ui" line="4481"/>
        <location filename="../win.ui" line="4526"/>
        <location filename="../win.ui" line="7973"/>
        <location filename="../win.ui" line="8019"/>
        <location filename="../win.ui" line="8536"/>
        <location filename="../win.ui" line="8621"/>
        <source>3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="234"/>
        <location filename="../win.ui" line="284"/>
        <location filename="../win.ui" line="802"/>
        <location filename="../win.ui" line="862"/>
        <location filename="../win.ui" line="1925"/>
        <location filename="../win.ui" line="1985"/>
        <location filename="../win.ui" line="3871"/>
        <location filename="../win.ui" line="4059"/>
        <location filename="../win.ui" line="4152"/>
        <location filename="../win.ui" line="4486"/>
        <location filename="../win.ui" line="4531"/>
        <location filename="../win.ui" line="7978"/>
        <location filename="../win.ui" line="8027"/>
        <location filename="../win.ui" line="8541"/>
        <location filename="../win.ui" line="8626"/>
        <source>4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="239"/>
        <location filename="../win.ui" line="289"/>
        <location filename="../win.ui" line="807"/>
        <location filename="../win.ui" line="867"/>
        <location filename="../win.ui" line="1930"/>
        <location filename="../win.ui" line="1990"/>
        <location filename="../win.ui" line="3876"/>
        <location filename="../win.ui" line="4064"/>
        <location filename="../win.ui" line="4157"/>
        <location filename="../win.ui" line="4491"/>
        <location filename="../win.ui" line="4536"/>
        <location filename="../win.ui" line="7983"/>
        <location filename="../win.ui" line="8032"/>
        <location filename="../win.ui" line="8546"/>
        <location filename="../win.ui" line="8631"/>
        <source>5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="244"/>
        <location filename="../win.ui" line="294"/>
        <location filename="../win.ui" line="812"/>
        <location filename="../win.ui" line="872"/>
        <location filename="../win.ui" line="1935"/>
        <location filename="../win.ui" line="1995"/>
        <location filename="../win.ui" line="3881"/>
        <location filename="../win.ui" line="4069"/>
        <location filename="../win.ui" line="4162"/>
        <location filename="../win.ui" line="4496"/>
        <location filename="../win.ui" line="4541"/>
        <location filename="../win.ui" line="7988"/>
        <location filename="../win.ui" line="8037"/>
        <location filename="../win.ui" line="8551"/>
        <location filename="../win.ui" line="8636"/>
        <source>6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="249"/>
        <location filename="../win.ui" line="299"/>
        <location filename="../win.ui" line="817"/>
        <location filename="../win.ui" line="877"/>
        <location filename="../win.ui" line="1940"/>
        <location filename="../win.ui" line="3886"/>
        <location filename="../win.ui" line="4074"/>
        <location filename="../win.ui" line="4167"/>
        <location filename="../win.ui" line="4501"/>
        <location filename="../win.ui" line="7993"/>
        <location filename="../win.ui" line="8556"/>
        <source>7</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="254"/>
        <location filename="../win.ui" line="304"/>
        <location filename="../win.ui" line="822"/>
        <location filename="../win.ui" line="882"/>
        <location filename="../win.ui" line="1945"/>
        <location filename="../win.ui" line="3891"/>
        <location filename="../win.ui" line="4079"/>
        <location filename="../win.ui" line="4172"/>
        <location filename="../win.ui" line="4506"/>
        <location filename="../win.ui" line="7998"/>
        <location filename="../win.ui" line="8561"/>
        <location filename="../win.ui" line="9227"/>
        <source>8</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="259"/>
        <location filename="../win.ui" line="309"/>
        <location filename="../win.ui" line="827"/>
        <location filename="../win.ui" line="887"/>
        <location filename="../win.ui" line="1950"/>
        <location filename="../win.ui" line="3896"/>
        <location filename="../win.ui" line="4177"/>
        <location filename="../win.ui" line="4511"/>
        <location filename="../win.ui" line="8566"/>
        <location filename="../win.ui" line="9232"/>
        <source>9</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="264"/>
        <location filename="../win.ui" line="832"/>
        <location filename="../win.ui" line="1955"/>
        <location filename="../win.ui" line="3901"/>
        <location filename="../win.ui" line="4084"/>
        <location filename="../win.ui" line="4182"/>
        <location filename="../win.ui" line="8571"/>
        <source>10</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="837"/>
        <location filename="../win.ui" line="1960"/>
        <location filename="../win.ui" line="8576"/>
        <source>11</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="842"/>
        <location filename="../win.ui" line="1965"/>
        <location filename="../win.ui" line="8581"/>
        <source>12</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="314"/>
        <location filename="../win.cpp" line="4521"/>
        <source>Battery type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="322"/>
        <location filename="../win.ui" line="338"/>
        <location filename="../win.ui" line="354"/>
        <location filename="../win.ui" line="370"/>
        <location filename="../win.ui" line="402"/>
        <location filename="../win.ui" line="418"/>
        <location filename="../win.ui" line="450"/>
        <location filename="../win.ui" line="466"/>
        <location filename="../win.ui" line="498"/>
        <location filename="../win.ui" line="546"/>
        <location filename="../win.ui" line="562"/>
        <location filename="../win.ui" line="639"/>
        <location filename="../win.ui" line="921"/>
        <location filename="../win.ui" line="942"/>
        <location filename="../win.ui" line="995"/>
        <location filename="../win.ui" line="1043"/>
        <location filename="../win.ui" line="1091"/>
        <location filename="../win.ui" line="1139"/>
        <location filename="../win.ui" line="1155"/>
        <location filename="../win.ui" line="1171"/>
        <location filename="../win.ui" line="1187"/>
        <location filename="../win.ui" line="1203"/>
        <location filename="../win.ui" line="1219"/>
        <location filename="../win.ui" line="1251"/>
        <location filename="../win.ui" line="1288"/>
        <location filename="../win.ui" line="1320"/>
        <location filename="../win.ui" line="1811"/>
        <location filename="../win.ui" line="1819"/>
        <location filename="../win.ui" line="1827"/>
        <location filename="../win.ui" line="1835"/>
        <location filename="../win.ui" line="1843"/>
        <location filename="../win.ui" line="1851"/>
        <location filename="../win.ui" line="1859"/>
        <location filename="../win.ui" line="1867"/>
        <location filename="../win.ui" line="8058"/>
        <location filename="../win.ui" line="8082"/>
        <location filename="../win.ui" line="8130"/>
        <location filename="../win.ui" line="8154"/>
        <location filename="../win.ui" line="8178"/>
        <location filename="../win.ui" line="8202"/>
        <location filename="../win.ui" line="8250"/>
        <location filename="../win.ui" line="8889"/>
        <location filename="../win.ui" line="9275"/>
        <location filename="../win.ui" line="9307"/>
        <location filename="../win.ui" line="9454"/>
        <location filename="../win.ui" line="9518"/>
        <location filename="../win.ui" line="9582"/>
        <location filename="../win.ui" line="9646"/>
        <source>-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="346"/>
        <location filename="../win.cpp" line="4665"/>
        <source>ProtocolVersion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="362"/>
        <source>BMS Comm. type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="378"/>
        <source>serial port 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="386"/>
        <location filename="../win.ui" line="434"/>
        <location filename="../win.ui" line="482"/>
        <location filename="../win.ui" line="530"/>
        <location filename="../win.ui" line="578"/>
        <source>bps</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="394"/>
        <location filename="../win.cpp" line="4674"/>
        <source>UserPassPort</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="410"/>
        <location filename="../win.cpp" line="4539"/>
        <source>Power control type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="426"/>
        <location filename="../win.cpp" line="4601"/>
        <source>serial port 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="442"/>
        <location filename="../win.cpp" line="4683"/>
        <source>RootPassport</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="458"/>
        <source>EMS Comm. type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="474"/>
        <location filename="../win.cpp" line="4610"/>
        <source>serial port 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="490"/>
        <location filename="../win.cpp" line="4692"/>
        <source>Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="506"/>
        <location filename="../win.cpp" line="4561"/>
        <source>Output power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="514"/>
        <location filename="../win.ui" line="602"/>
        <location filename="../win.ui" line="979"/>
        <location filename="../win.ui" line="6269"/>
        <location filename="../win.ui" line="6296"/>
        <location filename="../win.ui" line="8106"/>
        <location filename="../win.ui" line="8857"/>
        <location filename="../win.ui" line="8905"/>
        <location filename="../win.ui" line="8921"/>
        <location filename="../win.ui" line="9033"/>
        <source>kW</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="522"/>
        <location filename="../win.cpp" line="4620"/>
        <source>serial port 4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="538"/>
        <source>System upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="570"/>
        <location filename="../win.cpp" line="4629"/>
        <source>serial port 5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="586"/>
        <location filename="../win.cpp" line="4714"/>
        <source>Sounds</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="610"/>
        <location filename="../win.cpp" line="4647"/>
        <source>Can port 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="618"/>
        <location filename="../win.ui" line="671"/>
        <source>kbps</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8897"/>
        <location filename="../win.cpp" line="3495"/>
        <location filename="../win.cpp" line="3504"/>
        <source>Charge power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="663"/>
        <location filename="../win.cpp" line="4656"/>
        <source>Can port 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8913"/>
        <source>Discharge power limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8737"/>
        <source>Charge Vol. upper Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1075"/>
        <location filename="../win.ui" line="1123"/>
        <location filename="../win.ui" line="5498"/>
        <location filename="../win.ui" line="8346"/>
        <location filename="../win.ui" line="8713"/>
        <location filename="../win.ui" line="8745"/>
        <location filename="../win.ui" line="8777"/>
        <location filename="../win.ui" line="8793"/>
        <location filename="../win.ui" line="8809"/>
        <location filename="../win.ui" line="8825"/>
        <location filename="../win.ui" line="9291"/>
        <location filename="../win.ui" line="9323"/>
        <location filename="../win.ui" line="9339"/>
        <location filename="../win.ui" line="9384"/>
        <location filename="../win.ui" line="9400"/>
        <location filename="../win.ui" line="9598"/>
        <location filename="../win.ui" line="9662"/>
        <source>V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8801"/>
        <source>Discharge Vol. lower Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="747"/>
        <source>System parameter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="892"/>
        <source>Change rate of power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="900"/>
        <source>kW/s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="908"/>
        <location filename="../win.cpp" line="4867"/>
        <source>Machine type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="929"/>
        <location filename="../win.cpp" line="4966"/>
        <source>Module Number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="950"/>
        <location filename="../win.cpp" line="4767"/>
        <source>Grid frequency upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="963"/>
        <location filename="../win.ui" line="1011"/>
        <location filename="../win.ui" line="1027"/>
        <location filename="../win.ui" line="1235"/>
        <source>Hz</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="971"/>
        <location filename="../win.cpp" line="4876"/>
        <source>Machine capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="987"/>
        <location filename="../win.cpp" line="4975"/>
        <source>Restore factory</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1003"/>
        <location filename="../win.cpp" line="4776"/>
        <source>Grid frequency lower limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1019"/>
        <source>Output Fre. grade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1131"/>
        <location filename="../win.cpp" line="5002"/>
        <source>Clear Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1059"/>
        <location filename="../win.ui" line="1107"/>
        <location filename="../win.ui" line="5552"/>
        <location filename="../win.ui" line="5579"/>
        <location filename="../win.ui" line="8649"/>
        <location filename="../win.ui" line="8665"/>
        <location filename="../win.ui" line="8681"/>
        <location filename="../win.ui" line="8697"/>
        <location filename="../win.ui" line="8937"/>
        <location filename="../win.ui" line="8953"/>
        <location filename="../win.ui" line="8969"/>
        <location filename="../win.ui" line="8985"/>
        <location filename="../win.ui" line="9001"/>
        <location filename="../win.ui" line="9017"/>
        <source>%</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1067"/>
        <source>Output vol. level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1147"/>
        <location filename="../win.cpp" line="4803"/>
        <source>HVRT enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1163"/>
        <location filename="../win.cpp" line="4912"/>
        <source>Output reactive power mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1179"/>
        <location filename="../win.cpp" line="4812"/>
        <source>LVRT enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1211"/>
        <location filename="../win.cpp" line="4821"/>
        <source>AFD enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1227"/>
        <location filename="../win.cpp" line="4930"/>
        <source>Primary FM dead zone</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1243"/>
        <location filename="../win.cpp" line="4831"/>
        <source>Insulation detection enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1259"/>
        <location filename="../win.cpp" line="4939"/>
        <source>PFM coeff</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1267"/>
        <source>kW/Hz</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1280"/>
        <location filename="../win.cpp" line="4840"/>
        <source>PrimaryFreq enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1296"/>
        <location filename="../win.cpp" line="4948"/>
        <source>Grid recover time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="687"/>
        <location filename="../win.ui" line="735"/>
        <location filename="../win.ui" line="1304"/>
        <source>s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="35"/>
        <source>PCS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="626"/>
        <location filename="../win.cpp" line="4723"/>
        <source>Energy Meter Model</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="679"/>
        <source>BMS Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="727"/>
        <source>EMS Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1035"/>
        <source>Backup setup parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1083"/>
        <source>Restore backup setup parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1115"/>
        <location filename="../win.cpp" line="4903"/>
        <source>Transformer Turns Ratio</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1312"/>
        <location filename="../win.cpp" line="4849"/>
        <source>Inertia enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1336"/>
        <location filename="../win.cpp" line="4858"/>
        <source>CV parallel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1364"/>
        <source>External device</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1395"/>
        <source>DI_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1405"/>
        <source>DI_2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1415"/>
        <source>DI_3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1425"/>
        <source>DI_4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1435"/>
        <source>DI_5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1445"/>
        <source>DI_6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1485"/>
        <source>Enable/Disable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1490"/>
        <source>NC/NO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1495"/>
        <location filename="../win.ui" line="1796"/>
        <source>Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1500"/>
        <source>Function description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1537"/>
        <source>Access Control</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1545"/>
        <source>Full Power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1553"/>
        <source>Smoke</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1561"/>
        <source>Temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1580"/>
        <location filename="../win.ui" line="1624"/>
        <location filename="../win.ui" line="1668"/>
        <source>N_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1602"/>
        <source>Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1646"/>
        <location filename="../win.ui" line="1690"/>
        <source>Reserve</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1705"/>
        <source>BMS protection</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1736"/>
        <source>DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1746"/>
        <location filename="../win.cpp" line="5182"/>
        <source>Prohibit charging</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1756"/>
        <location filename="../win.cpp" line="5191"/>
        <source>Prohibit discharging</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1801"/>
        <source>Charge power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1806"/>
        <source>Discharge power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1879"/>
        <source>Debug</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2000"/>
        <location filename="../win.cpp" line="5289"/>
        <source>Debug variable 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2008"/>
        <source>1.5V Voltage revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2016"/>
        <source>INV A inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2021"/>
        <location filename="../win.cpp" line="5297"/>
        <source>Debug variable 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2029"/>
        <source> Bus Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2037"/>
        <source>INV B inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2042"/>
        <location filename="../win.cpp" line="5305"/>
        <source>Debug variable 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2050"/>
        <source>Grid A/AB Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2055"/>
        <source>INV C inductance Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2060"/>
        <source>Debug variable 1 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2068"/>
        <source>Grid B/BC Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2073"/>
        <location filename="../win.cpp" line="5489"/>
        <source>INV On off flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2078"/>
        <source>Debug variable 2 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2086"/>
        <source>Grid C/CA Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2091"/>
        <location filename="../win.cpp" line="5497"/>
        <source>Logic state</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2096"/>
        <source>Debug variable 3 address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2104"/>
        <source>Output A Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2109"/>
        <location filename="../win.cpp" line="5505"/>
        <source>INV flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2114"/>
        <source>Debug memery var. 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2122"/>
        <source>Output B Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2127"/>
        <location filename="../win.cpp" line="5513"/>
        <source>Grid flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2132"/>
        <source>Debug memery var. 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2140"/>
        <source>Output C Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2145"/>
        <location filename="../win.cpp" line="5521"/>
        <source>Grid protect flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2150"/>
        <source>Debug memery var. 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2158"/>
        <source>INV A Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2163"/>
        <location filename="../win.cpp" line="5529"/>
        <source>Bat flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2168"/>
        <source>Input Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2176"/>
        <source>INV B Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2181"/>
        <location filename="../win.cpp" line="5537"/>
        <source>DC bus flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2189"/>
        <source>Input. Cur. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2197"/>
        <source>INV C Vol. revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2202"/>
        <location filename="../win.cpp" line="5545"/>
        <source>INT main flag</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2210"/>
        <location filename="../win.cpp" line="5553"/>
        <source>parallel signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2220"/>
        <source>MonitorDebug</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2232"/>
        <source>DO control:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2244"/>
        <source>DO_TurnON_btn</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2257"/>
        <source>DO_TurnOFF_btn</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2271"/>
        <source>Soft start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2283"/>
        <source>Local_on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2296"/>
        <source>Local_off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2310"/>
        <location filename="../win.cpp" line="5608"/>
        <source>test data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4232"/>
        <source>Converter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4271"/>
        <source>Grid</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4310"/>
        <source>Load</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4546"/>
        <location filename="../win.cpp" line="1896"/>
        <location filename="../win.cpp" line="1899"/>
        <source>DC input breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4551"/>
        <location filename="../win.cpp" line="1904"/>
        <location filename="../win.cpp" line="3187"/>
        <source>converter available</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4556"/>
        <source>DO1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4561"/>
        <location filename="../win.cpp" line="1896"/>
        <location filename="../win.cpp" line="1899"/>
        <location filename="../win.cpp" line="3133"/>
        <source>DC contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4566"/>
        <location filename="../win.cpp" line="1904"/>
        <location filename="../win.cpp" line="3196"/>
        <source>DC Soft start</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4571"/>
        <location filename="../win.cpp" line="1907"/>
        <location filename="../win.cpp" line="3241"/>
        <source>DO2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4576"/>
        <location filename="../win.cpp" line="1897"/>
        <location filename="../win.cpp" line="1900"/>
        <location filename="../win.cpp" line="3142"/>
        <source>Output contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4581"/>
        <location filename="../win.cpp" line="1905"/>
        <location filename="../win.cpp" line="3205"/>
        <source>converter status</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4586"/>
        <location filename="../win.cpp" line="1908"/>
        <location filename="../win.cpp" line="3250"/>
        <source>DO3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4591"/>
        <location filename="../win.cpp" line="1897"/>
        <location filename="../win.cpp" line="1900"/>
        <source>Output breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4596"/>
        <location filename="../win.cpp" line="1905"/>
        <source>Reactive power Regulation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4601"/>
        <source>DI1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4606"/>
        <location filename="../win.cpp" line="1901"/>
        <location filename="../win.cpp" line="3160"/>
        <source>Grid contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4611"/>
        <location filename="../win.cpp" line="1905"/>
        <location filename="../win.cpp" line="3223"/>
        <source>LVRT</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4616"/>
        <source>DI2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4621"/>
        <location filename="../win.cpp" line="1897"/>
        <location filename="../win.cpp" line="1901"/>
        <source>Grid breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4631"/>
        <source>DI3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4641"/>
        <source>DI4</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4646"/>
        <source>DI5</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4651"/>
        <source>DI6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4719"/>
        <source>Please enter search keywords</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4738"/>
        <source>Search</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4781"/>
        <source>Battery Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6428"/>
        <source>prompt:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6453"/>
        <source>Normal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6646"/>
        <source>Alarm level:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6727"/>
        <location filename="../win.ui" line="6783"/>
        <location filename="../win.cpp" line="3214"/>
        <location filename="../win.cpp" line="3241"/>
        <location filename="../win.cpp" line="3250"/>
        <location filename="../win.cpp" line="3259"/>
        <location filename="../win.cpp" line="3268"/>
        <location filename="../win.cpp" line="3277"/>
        <location filename="../win.cpp" line="3286"/>
        <location filename="../win.cpp" line="3295"/>
        <location filename="../win.cpp" line="3304"/>
        <location filename="../win.cpp" line="3411"/>
        <location filename="../win.cpp" line="5031"/>
        <source>Disable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3906"/>
        <location filename="../win.ui" line="3916"/>
        <location filename="../win.ui" line="4959"/>
        <location filename="../win.ui" line="5728"/>
        <location filename="../win.ui" line="9237"/>
        <location filename="../win.ui" line="9252"/>
        <location filename="../win.cpp" line="1035"/>
        <location filename="../win.cpp" line="1206"/>
        <location filename="../win.cpp" line="1261"/>
        <location filename="../win.cpp" line="1305"/>
        <location filename="../win.cpp" line="1366"/>
        <location filename="../win.cpp" line="1922"/>
        <source>Name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3911"/>
        <location filename="../win.ui" line="3921"/>
        <location filename="../win.ui" line="5239"/>
        <location filename="../win.ui" line="5969"/>
        <location filename="../win.ui" line="9242"/>
        <location filename="../win.ui" line="9257"/>
        <location filename="../win.cpp" line="1035"/>
        <location filename="../win.cpp" line="1206"/>
        <location filename="../win.cpp" line="1261"/>
        <location filename="../win.cpp" line="1305"/>
        <location filename="../win.cpp" line="1922"/>
        <source>Value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4741"/>
        <source>120</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5468"/>
        <location filename="../win.ui" line="6188"/>
        <location filename="../win.ui" line="9247"/>
        <location filename="../win.ui" line="9262"/>
        <location filename="../win.cpp" line="1035"/>
        <source>Unit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5525"/>
        <location filename="../win.ui" line="6215"/>
        <location filename="../win.ui" line="6242"/>
        <location filename="../win.ui" line="8298"/>
        <location filename="../win.ui" line="8841"/>
        <location filename="../win.ui" line="8873"/>
        <source>A</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6323"/>
        <location filename="../win.ui" line="6350"/>
        <source>kWh</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4992"/>
        <source>Bat voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1455"/>
        <source>DO_1   </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1465"/>
        <source>DO_2    </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1475"/>
        <source>DO_3    </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3713"/>
        <source>Converter Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4342"/>
        <source>Converter State</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4676"/>
        <source>Converter Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5022"/>
        <location filename="../win.cpp" line="2694"/>
        <source>Bat current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5052"/>
        <location filename="../win.cpp" line="2698"/>
        <source>SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5082"/>
        <location filename="../win.cpp" line="2702"/>
        <source>SOH</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5112"/>
        <source>Cell voltage (max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5142"/>
        <source>Cell voltage (min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5172"/>
        <source>Cell temp. (max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5202"/>
        <source>Cell temp. (min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3382"/>
        <source>600</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3373"/>
        <source>100</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5606"/>
        <location filename="../win.ui" line="5633"/>
        <location filename="../win.ui" line="8729"/>
        <location filename="../win.ui" line="8761"/>
        <source>mV</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5660"/>
        <location filename="../win.ui" line="5687"/>
        <source>℃</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5755"/>
        <location filename="../win.cpp" line="2722"/>
        <source>Charging current limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5782"/>
        <location filename="../win.cpp" line="2726"/>
        <source>Discharging current limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5809"/>
        <location filename="../win.cpp" line="2730"/>
        <source>Allowable charging power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5837"/>
        <location filename="../win.cpp" line="2734"/>
        <source>Allowable discharging power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5864"/>
        <location filename="../win.cpp" line="2738"/>
        <source>Allowable charging energy</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5891"/>
        <location filename="../win.cpp" line="2742"/>
        <source>Allowable discharging energy</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6500"/>
        <source>Level1 </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6547"/>
        <source>Level2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6594"/>
        <source>Level3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6699"/>
        <source>Charging
enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6755"/>
        <source>Discharging
enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6829"/>
        <source>Data report</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6883"/>
        <source>Discharge:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6911"/>
        <source>1.1
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6937"/>
        <location filename="../win.ui" line="7177"/>
        <source>Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6974"/>
        <location filename="../win.ui" line="7028"/>
        <source>339
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="6994"/>
        <location filename="../win.ui" line="7231"/>
        <source>Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7048"/>
        <location filename="../win.ui" line="7285"/>
        <source>Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7082"/>
        <source>585.1
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7102"/>
        <location filename="../win.ui" line="7339"/>
        <source>Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7129"/>
        <source>Charge:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7157"/>
        <source>2.4
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7211"/>
        <location filename="../win.ui" line="7265"/>
        <source>2.6
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7319"/>
        <source>184.2
kW.h</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7399"/>
        <source>M  -</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7418"/>
        <source>Y  -</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7454"/>
        <source>M  +</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7473"/>
        <source>Y  +</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7502"/>
        <source>Export Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7540"/>
        <source>Note:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7557"/>
        <source>Out put file:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7593"/>
        <source>Log.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7611"/>
        <source>Report.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7656"/>
        <source>Data To Export</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7886"/>
        <source>History Record</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7801"/>
        <location filename="../win.ui" line="7905"/>
        <location filename="../win.cpp" line="2258"/>
        <source>Operation Log</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7941"/>
        <source>Parameter setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8066"/>
        <location filename="../win.cpp" line="3393"/>
        <source>Control mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8090"/>
        <source>Constant power (AC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8114"/>
        <location filename="../win.cpp" line="3402"/>
        <source>Machine number</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8162"/>
        <source>Parallel </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8138"/>
        <source>Work mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8186"/>
        <location filename="../win.cpp" line="3355"/>
        <source>Output power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8234"/>
        <location filename="../win.cpp" line="3364"/>
        <source>Output reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8282"/>
        <location filename="../win.cpp" line="3373"/>
        <source>Constant current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8330"/>
        <location filename="../win.cpp" line="3382"/>
        <source>Constant voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8444"/>
        <source>  Title</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8476"/>
        <location filename="../win.cpp" line="5682"/>
        <source>Return</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8485"/>
        <source>Battery setup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9071"/>
        <location filename="../win.cpp" line="2334"/>
        <source>Battery power on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9090"/>
        <location filename="../win.cpp" line="2338"/>
        <source>Battery power off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9192"/>
        <location filename="../win.ui" line="9197"/>
        <location filename="../win.ui" line="9202"/>
        <location filename="../win.ui" line="9207"/>
        <location filename="../win.ui" line="9212"/>
        <location filename="../win.ui" line="9217"/>
        <location filename="../win.ui" line="9222"/>
        <source>New Row</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9267"/>
        <location filename="../win.cpp" line="3658"/>
        <source>Capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9283"/>
        <source>Grid off EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9299"/>
        <source>Cell number(2V)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9315"/>
        <source>Grid on EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9331"/>
        <location filename="../win.cpp" line="3668"/>
        <source>Battery float voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9347"/>
        <source>Shutdown voltage point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9392"/>
        <location filename="../win.cpp" line="3673"/>
        <source>Battery filling voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9408"/>
        <source>Mending center point</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9462"/>
        <location filename="../win.cpp" line="3678"/>
        <source>Charge limiting value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9470"/>
        <location filename="../win.ui" line="9534"/>
        <location filename="../win.ui" line="9695"/>
        <location filename="../win.ui" line="9711"/>
        <source>C</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9478"/>
        <source>Temperature filling coefficient</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9526"/>
        <location filename="../win.cpp" line="3683"/>
        <source>Discharge limiting value</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9542"/>
        <source>Mending allowable setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9606"/>
        <source>Temperature alarm upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9670"/>
        <location filename="../win.cpp" line="3708"/>
        <source>Uniform charging and flushing current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9703"/>
        <location filename="../win.cpp" line="3713"/>
        <source>Float turn uniform charging current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8641"/>
        <source>DOD_OnGrid:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="2591"/>
        <source>100kW-TS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7575"/>
        <source>Record.csv</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7702"/>
        <source>status:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7735"/>
        <source>u disk disconnect!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7770"/>
        <location filename="../win.cpp" line="2254"/>
        <source>Historical Failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7835"/>
        <location filename="../win.cpp" line="2262"/>
        <source>Electricity Statistical Table</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="7866"/>
        <location filename="../win.cpp" line="2266"/>
        <source>Eject U disk</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8042"/>
        <source>Grid conected mode of the converter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8657"/>
        <source>Turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8673"/>
        <source>DOD_OffGrid:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8689"/>
        <source>Turn off SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8705"/>
        <source>Charge Vol. upper Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8721"/>
        <source>Turn on cell vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8769"/>
        <source>Discharge Vol. lower Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8753"/>
        <source>Turn off cell vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8833"/>
        <source>Charge Cur. Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8785"/>
        <source>Turn on total vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8929"/>
        <location filename="../win.cpp" line="3513"/>
        <source>Generator turn off SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8817"/>
        <source>Turn off total vol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8945"/>
        <source>Generator turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8849"/>
        <source>UPS charge power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8961"/>
        <source>Generator charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8881"/>
        <source>Monthly cycle time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1513"/>
        <source>Dry Contact EPO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1529"/>
        <source>Dry Contact Shutdown</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1766"/>
        <source>Level 1 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1776"/>
        <source>Level 2 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1786"/>
        <source>Level 3 Alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8586"/>
        <source>13</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8591"/>
        <source>14</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8596"/>
        <source>15</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8601"/>
        <source>16</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8606"/>
        <source>17</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8865"/>
        <source>Discharge Cur. Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8977"/>
        <location filename="../win.cpp" line="3540"/>
        <source>Grid charge SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8993"/>
        <location filename="../win.cpp" line="3549"/>
        <source>Charge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9009"/>
        <location filename="../win.cpp" line="3558"/>
        <source>Discharge Stop SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9025"/>
        <source>Grid capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9101"/>
        <source>Lead</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9157"/>
        <source>A1: Generator turn on voltage
B1: Generator turn off voltage
A1 Setting range: [250, 900]
B1 Setting range: [250, 900]
Set rule:B1 - A1 ≥ 10V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9726"/>
        <source>Automatic operation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9741"/>
        <source>SystemInformation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9756"/>
        <source>Version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9772"/>
        <location filename="../win.ui" line="9777"/>
        <location filename="../win.ui" line="9782"/>
        <location filename="../win.ui" line="9787"/>
        <location filename="../win.ui" line="9792"/>
        <source>新建行</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9797"/>
        <location filename="../win.ui" line="9802"/>
        <source>新建列</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9807"/>
        <location filename="../win.cpp" line="4470"/>
        <source>Monitoring software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9822"/>
        <source>Protocol version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9827"/>
        <location filename="../win.cpp" line="4488"/>
        <source>Converter software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9832"/>
        <location filename="../win.cpp" line="4497"/>
        <source>CPLD software version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9837"/>
        <source>SN:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9846"/>
        <source>Network</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9905"/>
        <source>              interface:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9946"/>
        <source>Port:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10013"/>
        <source>DHCP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10032"/>
        <source>STATIC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10048"/>
        <source>ip：</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10061"/>
        <source>netmask:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10077"/>
        <source>gateway:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10090"/>
        <source>Server ip:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10103"/>
        <source>192 . 168 . 1 . 100</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10116"/>
        <source>255 . 255 . 255 . 0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10129"/>
        <source>192 . 168 .  1  . 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10142"/>
        <source> 192 . 168 . 1  . 200</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10165"/>
        <location filename="../win.cpp" line="2303"/>
        <source>Apply and Restart system</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9927"/>
        <source>eth0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9965"/>
        <source>502</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10249"/>
        <source>Menu</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10283"/>
        <source>M_01 Converter turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="10323"/>
        <source>Current mode:CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1052"/>
        <source>Advance setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1157"/>
        <location filename="../win.cpp" line="3723"/>
        <source>Check</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1157"/>
        <source>StartTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1157"/>
        <source>EndTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1157"/>
        <location filename="../win.cpp" line="3726"/>
        <source>State</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1157"/>
        <source>Power(kW)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2747"/>
        <source>Alarm levels uploaded from BMS, level one alarm is yellow, level two alarm is orange, and level three alarm is red;
By default, the converter does not respond to level one and level two alarms, but shuts down in response to level three alarms.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2773"/>
        <source>Inv. side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2782"/>
        <source>Inv. side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2791"/>
        <source>Inv. side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2800"/>
        <source>Inv. side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2809"/>
        <source>Inv. side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2827"/>
        <source>Active power P on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2836"/>
        <source>Reactive power Q on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2845"/>
        <source>Apparent power S on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2855"/>
        <source>Power factor PF on the inv. side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2864"/>
        <source>Converter battery side voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2873"/>
        <source>Converter battery side current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2882"/>
        <source>Converter battery side power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2891"/>
        <source>Converter bus voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2900"/>
        <source>The IGBT temperature of the converter: The IGBT temperature must not exceed 102°C. Otherwise, the converter will operate at a reduced capacity. It will resume full power operation when the temperature drops to 73°C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2909"/>
        <source>”The ambient temperature.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2924"/>
        <source>Grid side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2933"/>
        <source>Grid side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2942"/>
        <source>Grid side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2951"/>
        <source>Grid side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2960"/>
        <source>Grid side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2969"/>
        <source>Grid side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2978"/>
        <source>Active power P on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2987"/>
        <source>Reactive power Q on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2996"/>
        <source>Apparent power S on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3005"/>
        <source>Frequency on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3014"/>
        <source>Power factor PF on the grid side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3029"/>
        <source>Load side AB line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3038"/>
        <source>Load side BC line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3047"/>
        <source>Load side CA line voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3056"/>
        <source>Load side A phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3065"/>
        <source>Load side B phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3074"/>
        <source>Load side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3083"/>
        <source>Active power P on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3092"/>
        <source>Reactive power Q on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3101"/>
        <source>Apparent power S on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3110"/>
        <source>Power factor PF on the load side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3320"/>
        <source>Grid conected mode of the converter </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3321"/>
        <source>When &quot;Auto&quot; is selected, the converter will automatically switch between grid-on and grid-off. When the grid side is normal, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter operates in grid-off mode (VF).                                               When &quot;Grid-on&quot; is selected, the converter operates in grid-on mode (PQ).When the grid side is abnormal, the converter will shut down.                                               When &quot;Grid-off&quot; is selected, the converter operates in grid-off mode (VF).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3356"/>
        <source>This item can modify the power factor, where the power factor is equal to the ratio of active power to apparent power. A positive value indicates leading reactive power, while a negative value indicates lagging reactive power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3365"/>
        <source>This parameter can change the reactive power Q, positive value indicates leading reactive power, negative value indicates lagging reactive power.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3374"/>
        <location filename="../win.cpp" line="3394"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant voltage and modify the voltage value. Converter will operate at the constant voltage value and function as a constant voltage source.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3383"/>
        <source>Enter the advanced settings interface and select the control power mode. Choose constant current and modify the current value. Converter will charge or discharge the battery with this current value. Positive values represent discharging, while negative values represent charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3403"/>
        <source>Device number: You can set ID number, which can be set within the range of M_01 to M_12.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3412"/>
        <source>Parallel operation: When converter operates at grid-off mode in parallel, this item needs to be enabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3531"/>
        <source>Charging SOC of Diesel Generator</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3532"/>
        <source>Charging SOC of Diesel Generator: In grid expansion mode, when a diesel generator is connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3541"/>
        <source>Charging SOC of Grid: In grid expansion mode, when there is no diesel generator connected, the battery SOC will charge when it is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3550"/>
        <source>Discharging Stop SOC: In grid expansion mode, the battery will stop discharging when the battery SOC is below this SOC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3559"/>
        <source>Grid Capacity: The maximum power capacity connected to the grid in grid expansion mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4163"/>
        <location filename="../win.cpp" line="4177"/>
        <location filename="../win.cpp" line="4191"/>
        <location filename="../win.cpp" line="4205"/>
        <location filename="../win.cpp" line="4219"/>
        <location filename="../win.cpp" line="4233"/>
        <location filename="../win.cpp" line="4247"/>
        <location filename="../win.cpp" line="4261"/>
        <location filename="../win.cpp" line="4275"/>
        <location filename="../win.cpp" line="4289"/>
        <source>charge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4170"/>
        <location filename="../win.cpp" line="4184"/>
        <location filename="../win.cpp" line="4198"/>
        <location filename="../win.cpp" line="4212"/>
        <location filename="../win.cpp" line="4226"/>
        <location filename="../win.cpp" line="4240"/>
        <location filename="../win.cpp" line="4254"/>
        <location filename="../win.cpp" line="4268"/>
        <location filename="../win.cpp" line="4282"/>
        <location filename="../win.cpp" line="4296"/>
        <source>discharge</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1386"/>
        <source>Inverter overcurrent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1386"/>
        <location filename="../win.cpp" line="1398"/>
        <location filename="../win.cpp" line="1458"/>
        <location filename="../win.cpp" line="1470"/>
        <location filename="../win.cpp" line="1518"/>
        <location filename="../win.cpp" line="1530"/>
        <location filename="../win.cpp" line="1542"/>
        <location filename="../win.cpp" line="1554"/>
        <location filename="../win.cpp" line="1626"/>
        <location filename="../win.cpp" line="1650"/>
        <location filename="../win.cpp" line="1662"/>
        <location filename="../win.cpp" line="1698"/>
        <source>General failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1387"/>
        <source>Inductive current instantaneous value &gt;3lp or inductive current RMS value &gt;1.36ln</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1388"/>
        <source>PCS shut down and disconnect the output contactor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1389"/>
        <location filename="../win.cpp" line="1401"/>
        <location filename="../win.cpp" line="1413"/>
        <location filename="../win.cpp" line="1461"/>
        <location filename="../win.cpp" line="1473"/>
        <location filename="../win.cpp" line="1485"/>
        <location filename="../win.cpp" line="1497"/>
        <location filename="../win.cpp" line="1521"/>
        <location filename="../win.cpp" line="1557"/>
        <location filename="../win.cpp" line="1569"/>
        <location filename="../win.cpp" line="1581"/>
        <location filename="../win.cpp" line="1605"/>
        <location filename="../win.cpp" line="1617"/>
        <location filename="../win.cpp" line="1629"/>
        <location filename="../win.cpp" line="1653"/>
        <location filename="../win.cpp" line="1665"/>
        <location filename="../win.cpp" line="1677"/>
        <location filename="../win.cpp" line="1689"/>
        <location filename="../win.cpp" line="1701"/>
        <source>Recoverable, automatic recovery 5 minutes after the fault is eliminated</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1434"/>
        <source>DC bus overvoltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1435"/>
        <source>DC input voltage more then 850V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1446"/>
        <source>DC bus short circuit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2279"/>
        <source>Interface</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1989"/>
        <location filename="../win.cpp" line="1993"/>
        <location filename="../win.cpp" line="1997"/>
        <location filename="../win.cpp" line="2132"/>
        <location filename="../win.cpp" line="2191"/>
        <location filename="../win.cpp" line="2195"/>
        <location filename="../win.cpp" line="2199"/>
        <location filename="../win.cpp" line="2203"/>
        <location filename="../win.cpp" line="2207"/>
        <location filename="../win.cpp" line="2211"/>
        <location filename="../win.cpp" line="2215"/>
        <location filename="../win.cpp" line="2219"/>
        <location filename="../win.cpp" line="2223"/>
        <location filename="../win.cpp" line="2227"/>
        <location filename="../win.cpp" line="2231"/>
        <location filename="../win.cpp" line="2235"/>
        <location filename="../win.cpp" line="2239"/>
        <location filename="../win.cpp" line="2243"/>
        <location filename="../win.cpp" line="2247"/>
        <location filename="../win.cpp" line="2251"/>
        <location filename="../win.cpp" line="2255"/>
        <location filename="../win.cpp" line="2259"/>
        <location filename="../win.cpp" line="2263"/>
        <location filename="../win.cpp" line="2267"/>
        <location filename="../win.cpp" line="2280"/>
        <location filename="../win.cpp" line="2284"/>
        <location filename="../win.cpp" line="2288"/>
        <location filename="../win.cpp" line="2292"/>
        <location filename="../win.cpp" line="2296"/>
        <location filename="../win.cpp" line="2300"/>
        <location filename="../win.cpp" line="2304"/>
        <location filename="../win.cpp" line="2319"/>
        <location filename="../win.cpp" line="2323"/>
        <location filename="../win.cpp" line="2327"/>
        <location filename="../win.cpp" line="2331"/>
        <location filename="../win.cpp" line="2335"/>
        <location filename="../win.cpp" line="2339"/>
        <location filename="../win.cpp" line="2691"/>
        <location filename="../win.cpp" line="2695"/>
        <location filename="../win.cpp" line="2699"/>
        <location filename="../win.cpp" line="2703"/>
        <location filename="../win.cpp" line="2707"/>
        <location filename="../win.cpp" line="2711"/>
        <location filename="../win.cpp" line="2715"/>
        <location filename="../win.cpp" line="2719"/>
        <location filename="../win.cpp" line="2723"/>
        <location filename="../win.cpp" line="2727"/>
        <location filename="../win.cpp" line="2731"/>
        <location filename="../win.cpp" line="2735"/>
        <location filename="../win.cpp" line="2739"/>
        <location filename="../win.cpp" line="2743"/>
        <location filename="../win.cpp" line="2747"/>
        <location filename="../win.cpp" line="2751"/>
        <location filename="../win.cpp" line="2755"/>
        <location filename="../win.cpp" line="5577"/>
        <location filename="../win.cpp" line="5600"/>
        <location filename="../win.cpp" line="5608"/>
        <location filename="../win.cpp" line="5616"/>
        <location filename="../win.cpp" line="5682"/>
        <location filename="../win.cpp" line="5707"/>
        <source>OK</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1187"/>
        <location filename="../win.cpp" line="2772"/>
        <source>Inv. voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1187"/>
        <location filename="../win.cpp" line="2781"/>
        <source>Inv. voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1187"/>
        <location filename="../win.cpp" line="2790"/>
        <source>Inv. voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1188"/>
        <location filename="../win.cpp" line="2799"/>
        <source>Inv. current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1188"/>
        <location filename="../win.cpp" line="2808"/>
        <source>Inv. current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1188"/>
        <location filename="../win.cpp" line="2817"/>
        <source>Inv. current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1907"/>
        <location filename="../win.cpp" line="3232"/>
        <source>Start Diesel Generator Signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1908"/>
        <location filename="../win.cpp" line="3259"/>
        <source>Dry contact EPO</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1909"/>
        <location filename="../win.cpp" line="3268"/>
        <source>Dry contact Shutdown</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1989"/>
        <source>This is the converter off switch. Click to turn on and off the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1993"/>
        <source>This is the converter standby switch. Click the converter to enter the standby state.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1997"/>
        <source>This is the converter on switch, click to turn on the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2190"/>
        <source>Discharge Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2194"/>
        <source>Discharge Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2198"/>
        <source>Discharge Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2202"/>
        <source>Discharge Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2206"/>
        <source>Charge Day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2210"/>
        <source>Charge Month</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2214"/>
        <source>Charge Year</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2218"/>
        <source>Charge Total</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2222"/>
        <source>Month-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2226"/>
        <source>Year-</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2230"/>
        <source>Daily electricity quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2231"/>
        <source>To view the daily charge and discharge volume, click here to jump to the histogram of daily charge and discharge volume. The horizontal axis is in day, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2234"/>
        <source>Annual electricity quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2235"/>
        <source>To view the annual charge and discharge volume, click here to jump to the histogram of the annual charge and discharge volume, the horizontal axis is in year, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2238"/>
        <source>Month+</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2242"/>
        <source>Year+</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2246"/>
        <source>Monthly electric quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2247"/>
        <source>To view the monthly charge and discharge volume, click here to jump to the histogram of monthly charge and discharge volume. The horizontal axis is in month, and the vertical axis is in power (kWh).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2250"/>
        <source>Total electric quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2251"/>
        <source>To view the total charge and discharge, click here to jump to the overview chart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2283"/>
        <source>Port</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2287"/>
        <source>Ip</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2291"/>
        <source>Netmask</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2295"/>
        <source>Gateway</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2299"/>
        <source>Serber ip</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2304"/>
        <source>This is the application and restart the system. After clicking, the system will be restarted. If there is an upgrade of the monitoring screen program, the new monitoring screen program will be used after the restart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2358"/>
        <source>CAN communication failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2361"/>
        <source>Fire alarm (High temp. alarm)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2616"/>
        <source>Power control type：CP_P-&gt;CP_N&amp;&amp;P</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2619"/>
        <source>Power control type：CP_N&amp;&amp;P-&gt;CP_P</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2622"/>
        <source>Grid Fre Upper limit：0.2-&gt;3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2625"/>
        <source>Grid Fre Upper limit：3-&gt;0.2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2628"/>
        <source>Voltage protection Lower limit：-10-&gt;-15</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2631"/>
        <source>Voltage protection Lower limit：-15-&gt;-10</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2634"/>
        <source>Operation mode：Prevent countercurrnet-&gt;Peak valley</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2643"/>
        <source>Operation mode：UPS-&gt;Prevent countercurrnet</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2640"/>
        <source>Operation mode：Manual-&gt;UPS</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1988"/>
        <source>Turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1992"/>
        <source>Stand-by</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1996"/>
        <source>Turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2318"/>
        <source>DO turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2319"/>
        <source>This is the DO control closure, provided for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2322"/>
        <source>Do turn off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2323"/>
        <source>This is the DO control off, provided for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2326"/>
        <source>Local on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2327"/>
        <source>This is to start a local soft boot, only for internal debugging use.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2330"/>
        <source>Local off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2331"/>
        <source>This is to turn off the local soft boot for internal debugging use only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2637"/>
        <source>Operation mode：Peak valley-&gt;Manual</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2646"/>
        <source>Inv ON/Off-Grid：Off-&gt;automatic</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2649"/>
        <source>Inv ON/Off-Grid：automatic-&gt;Off</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2675"/>
        <source>Alarm name</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2675"/>
        <source>Alarm leve</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2675"/>
        <source>Trigger condition</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2676"/>
        <source>Response action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2676"/>
        <source>Whether to reset
automatically and reset time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2690"/>
        <source>Bat volage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2706"/>
        <source>Cell voltage(max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2710"/>
        <source>Cell voltage(min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2714"/>
        <source>Cell temp.(max)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2718"/>
        <source>Cell temp.(min)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2746"/>
        <source>Alarm level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1294"/>
        <location filename="../win.cpp" line="3109"/>
        <source>Load power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3124"/>
        <source>DC input Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3124"/>
        <location filename="../win.cpp" line="3133"/>
        <location filename="../win.cpp" line="3142"/>
        <location filename="../win.cpp" line="3151"/>
        <location filename="../win.cpp" line="3160"/>
        <location filename="../win.cpp" line="3169"/>
        <location filename="../win.cpp" line="3178"/>
        <source>On</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3125"/>
        <source>There are two states for a DC circuit breaker: On, Off.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3134"/>
        <source>The DC contactor has two states: On, Off. After the soft start of the DC side is completed, the DC contactor closes. When the DC side of the battery is disconnected and the voltage of the DC bus drops to a certain level, the DC contactor opens.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3143"/>
        <source>The output contactor has two states: On, Off. The output contactor closes after the soft start on the inv. side is completed. The output contactor opens when the converter is shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3151"/>
        <source>Output Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3161"/>
        <source>The grid contactor has two states: On, Off. When the inverter is in grid-connected mode and the grid voltage is normal, the grid contactor is closed. When the inverter is in island mode, the grid contactor is open. In the islanded state, the grid contactor remains open.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3179"/>
        <source>There are two states for the maintenance bypass circuit breaker: On, Off. This circuit breaker is only used for machine maintenance. If maintenance is required, please contact the maintenance personnel.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3730"/>
        <source>End time: The system stops automatically running when the system reaches this time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3733"/>
        <source>Start time: When the system reaches this time, it starts to run automatically.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3734"/>
        <source>Select: After this function is enabled, the system automatically runs the selected function mode within the specified period.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4912"/>
        <source>Non
adjustable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4921"/>
        <source>Non
countercurrent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3169"/>
        <source>Grid Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2131"/>
        <source>Alarm icon</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1189"/>
        <location filename="../win.cpp" line="2826"/>
        <source>Inv. active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1189"/>
        <location filename="../win.cpp" line="2835"/>
        <source>Inv. reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1189"/>
        <location filename="../win.cpp" line="2844"/>
        <source>Inv. apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1189"/>
        <location filename="../win.cpp" line="2854"/>
        <source>Inv. power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1366"/>
        <source>System Information</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2131"/>
        <source>Alarm icon: It is not displayed when there is no alarm. When there is a minor alarm, a yellow icon is displayed. When there is a fault alarm, a red icon is displayed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2191"/>
        <source>Display today&apos;s power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2195"/>
        <source>Display this month&apos;s power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2199"/>
        <source>Display this year&apos;s power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2203"/>
        <source>Display total power discharge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2207"/>
        <source>Display today&apos;s power charge amount</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2211"/>
        <source>Display this month&apos;s power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2215"/>
        <source>Display this year&apos;s power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2219"/>
        <source>Display total power charge amount.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2223"/>
        <source>To view the data of the previous month.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2227"/>
        <source>To view the data of the previous year.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2239"/>
        <source>To view the data of the next month.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2243"/>
        <source>To view the data of the next year.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2255"/>
        <source>Export History Records, click here to export the history records to a U disk. The exported file will be named Record.csv, and it needs to be opened with Excel.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2259"/>
        <source>Export operation log. Click here to export operation log to U disk.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2263"/>
        <source>Export the battery statistics. Click here to export the battery statistics to the U disk.
The accuracy is 0.1, which means that the obtained data multiplied by 0.1 gives the actual value.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2267"/>
        <source>Eject U disk.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2335"/>
        <source>Battery power-on: This function allows the BMS to send a command to close the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2339"/>
        <source>Battery power-off: This function allows the BMS to send a command to open the contactor (Note: this feature is only supported by some BMS manufacturers).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2353"/>
        <source>0 represents an alarm event, and this item will turn red. 1 represents a status event.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2355"/>
        <source>Event start time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2357"/>
        <source>Event end time: &apos;... &apos;indicates that there is no end time,&apos;-&apos; indicates that the event is in progress.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2359"/>
        <source>event description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2360"/>
        <source>event description.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2363"/>
        <source>Converter Standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2364"/>
        <source>The grid contactor connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2365"/>
        <source>The grid breaker connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2366"/>
        <source>The output breaker connected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2367"/>
        <source>Buck not softened</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2368"/>
        <source>Contactor off buck</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2370"/>
        <source>The grid breaker disconnected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2577"/>
        <source>System settings operation records.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2691"/>
        <source>Total voltage of the battery uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2695"/>
        <source>Total current of the battery uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2699"/>
        <source>Battery SOH uploaded from BMS, the percentage of available capacity after full charge compared to the rated capacity.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2703"/>
        <source>Battery SOC uploaded by BMS refers to the current remaining battery capacity percentage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2707"/>
        <source>The highest voltage of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2711"/>
        <source>The lowest voltage of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2715"/>
        <source>The highest temperature of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2719"/>
        <source>The lowest temperature of single cell uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2723"/>
        <source>The limit of charging current uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2727"/>
        <source>The limit of discharging current uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2731"/>
        <source>The allowable charging power uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2735"/>
        <source>The allowable discharging power uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2739"/>
        <source>The allowable charging capacity uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2743"/>
        <source>The allowable discharging capacity uploaded by BMS.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2750"/>
        <source>Charging enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2751"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to charge, Disable indicates the battery is not allowed to charge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2754"/>
        <source>Discharging enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2755"/>
        <source>Battery Status Uploaded by BMS: Enable indicates the battery is allowed to discharge, Disable indicates the battery is not allowed to discharge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2818"/>
        <source>Inv. side C phase current.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3152"/>
        <source>The output circuit breaker has two states: On, Off. It can only be manually opened and closed. If there is an overcurrent in the output circuit breaker, it will trip.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3170"/>
        <source>The power grid circuit breaker has two states: On, Off; The power grid circuit breaker can only be manually disconnected. If the power grid circuit breaker overflows, the power grid circuit breaker may trip.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3187"/>
        <source>Disabled</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3188"/>
        <source>The converter has two states: enabled,disabled. The converter is enabled when the self-check is successful. Otherwise, the converter is disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3197"/>
        <source>There are three states for DC soft start: Not starting, Soft starting, and Complete. Soft start refers to the process in which the converter charges the busbar with the battery during startup, causing the busbar voltage to rise close to the battery voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3206"/>
        <source>Converter states include: OFF, AC Soft Start, Grid-ON Charge, Grid-ON Discharge, Grid-OFF Discharge, Derating grid-on, Standby, Grid-OFF Charge, Constant Voltage Discharge and Constant Voltage Charge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3215"/>
        <source>There are three types of reactive power regulation: Disable,PF regulation, and  regulation.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3224"/>
        <source>LVRT states : enabled , disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3233"/>
        <source>Signal to start the diesel generator, start the diesel generator when enabled, stop the diesel generator when disabled.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3242"/>
        <source>Dry contact 2 is output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3251"/>
        <source>Dry contact 3 is output.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3260"/>
        <source>Dry contact EPO：Enable，Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3269"/>
        <source>Dry contact Shutdown：Enable，Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3277"/>
        <source>Access signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3278"/>
        <source>Access signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3287"/>
        <source>Full power signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3296"/>
        <source>Smoke alarm signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3304"/>
        <source>Fire fighting signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3305"/>
        <source>Fire fighting signal:Enable, Disable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3320"/>
        <source>automatic</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3332"/>
        <source>AC Side Power: You can control the charging and discharging power of the battery from the AC side by modifying this value. When the advanced setting for power control mode is set to Constant Power mode (CP_N&amp;P), a positive value indicates discharging, and a negative value indicates charging.
For example, setting it to -5 means that the AC side will charge the battery at a power of -5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3402"/>
        <source>M_01</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3427"/>
        <source>Grid-on DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3428"/>
        <source>Grid-on DOD, allowable depth of discharge in grid-on mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3436"/>
        <source>Grid-off DOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3437"/>
        <source>Grid-off DOD, allowable depth of discharge in grid-off mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3445"/>
        <source>Charge Volt upper Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3446"/>
        <source>Charging voltage upper limit: When the battery total voltage reaches this value during charging, the converter will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3455"/>
        <source>Charging voltage upper limit hysteresis: When the battery is charging, if the battery total voltage reaches the charging voltage upper limit, the converter will shut down. When the battery total voltage drops below the charging voltage upper limit minus the hysteresis value, the converter will automatically turn on.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3463"/>
        <source>Discharge Volt lower Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3464"/>
        <source>Discharge voltage lower limit: When the battery total voltage reaches this value during discharge, the converter will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3473"/>
        <source>Discharge voltage lower limit hysteresis: When the battery is discharging, if the battery total voltage drops below the discharge voltage lower limit, the converter will shut down. When the battery total voltage exceeds the discharge voltage lower limit plus the hysteresis value, the converter will automatically turn on.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3481"/>
        <source>Charge Current Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3482"/>
        <source>Charging current limit: The maximum allowable current on the battery side to prevent overcurrent during charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3490"/>
        <source>Discharge Current Limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3491"/>
        <source>Discharging current limit: The maximum allowable current on the battery side to prevent overcurrent during Discharging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3514"/>
        <source>When the specified SOC is reached, the diesel generator shuts down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3522"/>
        <source>Genertor turn on SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3523"/>
        <source>When the specified SOC is reached, the diesel generator starts.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3568"/>
        <source>Grid Capacity: The maximum capacity of the converter&apos;s AC side input, which takes effect in the converter power supply mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3587"/>
        <source>Start SOC: In UPS mode, when the battery SOC reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3596"/>
        <source>Stop SOC: In UPS mode, when the battery SOC reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3605"/>
        <source>Start cell voltage: In UPS mode, when the lowest voltage of a battery cell reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3614"/>
        <source>Stop cell voltage: In UPS mode, when the highest voltage of a battery cell reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3623"/>
        <source>Start total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3632"/>
        <source>Stop total voltage: In UPS mode, when the total voltage of the battery reaches that value, the converter stops charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3641"/>
        <source>Backup charging power: In UPS mode, the backup charging power of the converter when the battery starts charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3650"/>
        <source>Monthly cycling date: On the same day of each month, a deep discharge and recharge will be performed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3664"/>
        <source>The number of battery cells connected in series in the battery stack (based on a 2V unit).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3679"/>
        <source>Charging Current Limit: The maximum allowable current on the battery side to prevent overcurrent during charging. (Upper limit: 0.25C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3684"/>
        <source>Discharge Current Limit: The maximum allowable current on the battery side to prevent overcurrent during discharge. (Upper limit: 0.5C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3689"/>
        <source>Generator Shutdown Voltage: When the specified voltage is reached, the diesel generator will shut down.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3694"/>
        <source>Generator Start Voltage: When the specified voltage is reached, the diesel generator will start up.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3698"/>
        <source>Grid-off EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3699"/>
        <source>Grid-off discharge cut-off voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3703"/>
        <source>Grid-on EOD</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3704"/>
        <source>Grid-on discharge cut-off voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3709"/>
        <source>Uniform charging to flushing current: Upper limit of 0.025C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3714"/>
        <source>Float turn to uniform charging current: Upper limit of 0.15C.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3731"/>
        <source>This working state, which will be executed during working hours.  There are three options: charge, discharge, and Automatic.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3732"/>
        <source>Working power, which is executed according to the working state when working in this state, the positive number is discharging, and the negative number is charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4522"/>
        <source>Battery Types: Lithium, Lead-Acid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4531"/>
        <source>Battery Communication Modes: None, RS485, CAN, Ethernet. (Note: Due to the fact that CAN and Ethernet both have only one port, the battery communication mode and EMS communication mode cannot be selected as &quot;CAN&quot; or &quot;Ethernet&quot; simultaneously.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4540"/>
        <source>Constant Voltage (CV) mode: The converter will operate in constant voltage mode on the DC side.                                              Constant Current (CC) mode: The converter will operate in constant current mode on the DC side.                                              Constant Power AC (CP_AC) mode: The power level can be set at &quot;constant power.&quot; The value represents the power level, positive for discharge and negative for charge. For example, setting it to -5 means that the AC side will charge the battery with a power of 5 kW. Due to converter losses, the DC side power will be lower than the AC side power in this case. Conversely, setting it to 5 means that the AC side will output power at 5 kW. Due to converter losses, the DC side power will be higher than the AC side power in this case.                                              Reserved.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4552"/>
        <source>EMS communication methods: RS485, CAN, Ethernet.                                         The setting communication methods are readable and writable in remote mode, and only readable in local mode. The unselected communication methods are only readable in both remote and local mode.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4562"/>
        <source>Output Power Limit: Restricts the upper limit of the set value for the power on the AC side of the converter.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4571"/>
        <source>Battery Protocol: Parse the messages sent by BMS based on the selected battery protocol. Currently supported battery manufacturer protocols include:MEGA, LISHEN, PENGHUI, GAOTE, XIENENG, LANLI, SHENLAN, PAINENG, NINGDESHIDAI, SUOYING, XINGWANGDA, KUBO, GAOTE_V2, TOGOOD, GROUP_STANDARD, WOBO, KGOOER, LIDE, PAINENG_L, WEILAN, ALPHA, TUOPU, JIEHUI, JDI, ECUBE, FARO, BGS, JDITEC, HUASU, LIGAO.                                             
Select AUTO to automatically detect the battery manufacturer protocol.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="594"/>
        <location filename="../win.cpp" line="4581"/>
        <source>Anti-backflow power tolerance</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4582"/>
        <source>Anti-backflow power tolerance.The default power tolerance is 10 kW. When the output power increases to &quot;output power limit + power tolerance&quot;, the output power will be reduced to &quot;output power limit - power tolerance&quot;.
(Note: This setting only takes effect in the system anti-backflow mode and is used to control the power tolerance at the grid entrance).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="330"/>
        <location filename="../win.cpp" line="4592"/>
        <source>Serial Communication Address</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4593"/>
        <source>Serial Communication Address: The default value is 1, adjustable range is between 1 and 255, used for matching address during serial communication.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4602"/>
        <source>Serial Port 2 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 2 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4611"/>
        <source>Serial Port 3 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 3 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4621"/>
        <source>Serial Port 4 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 4 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4630"/>
        <source>Serial Port 5 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 5 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4638"/>
        <source>serial port 6</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4639"/>
        <source>Serial Port 6 has six selectable baud rates: 1200, 2400, 4800, 9600, 19200, and 38400. The default baud rate for Serial Port 6 is 9600 bps, with eight data bits, no parity, and one stop bit (8-N-1).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4648"/>
        <source>CAN1 Port: The baud rate for internal communication is 500 kbps by default and cannot be modified. </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4657"/>
        <source>CAN2 Port: Optional baud rates for the CAN2 port include 100, 125, 250, 500, and 800 kbps, with a default baud rate of 500 kbps.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4666"/>
        <source>Protocol version: View the current protocol version. The default protocol version number is V1.0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4675"/>
        <source>User password: Available for resetting the user password. The default user password is 123456. (Note: The user password must be six digits.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4684"/>
        <source>Admin password: Available for resetting the admin password. The default admin password is 888888. (Note: The admin password must be six digits.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4758"/>
        <source>Power change rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4759"/>
        <source>Power change rate: the rate at which power changes within a second .</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4768"/>
        <source>Upper limit of power grid frequency variation: The maximum range of frequency variation allowed on the AC side, which can be selected as 0.2, 0.5, 1, 5.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4777"/>
        <source>Lower limit of power grid frequency variation range: The maximum range of frequency variation allowed on the AC side, which can be selected as-0.5, -1, -2, -5.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4786"/>
        <source>Upper limit of voltage protection range: The maximum range of voltage variation allowed on the AC side, which can be selected as 10, 15, 20.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4795"/>
        <source>Lower limit of voltage protection range: The minimum range of voltage variation allowed on the AC side, which can be selected as -10, -15, -20.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4804"/>
        <source>High voltage ride through(HVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4813"/>
        <source>Low voltage ride through(LVRT) enablement: Enable, Disable. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4822"/>
        <source>Prevent islanding effect. When islanding effect is detected (in a photovoltaic grid-on system, when a power outage occurs in the main grid, and the PV grid-connected converter generates power that matches the local load on the low-voltage side of the grid, it can easily sustain power generation independently, resulting in an &apos;island&apos; phenomenon, which endangers the safety of maintenance personnel), the converter automatically shuts down. The options for this feature can be set as &apos;Enable&apos; or &apos;prohibited&apos; .(Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4832"/>
        <source>Insulation detection enable, the insulation resistance should be greater than 33KΩ for normal start-up and operation. If it is less than 33KΩ, it should not start, and an alarm should be triggered. By default, it is disabled, but can be set as &apos;Enable&apos; or &apos;prohibited&apos;.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4841"/>
        <source>Primary frequency control enable: When the grid frequency deviates from the rated value, the active power is controlled to increase or decrease in order to maintain the grid frequency at the rated value. It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4850"/>
        <source>Rotational inertia enable: It can be selected as enabled or disabled. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4859"/>
        <source>Constant voltage parallel operation enable: It can be selected as enabled or disabled.  (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4868"/>
        <source>Converter Model: As per factory settings, generally not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4877"/>
        <source>The rated capacity of the converter shall be based on the factory value and cannot be changed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4886"/>
        <source>Output Frequency Level: Default 50Hz, typically 50Hz or 60Hz.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4895"/>
        <source>Output Voltage Level: As per factory settings, generally not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4904"/>
        <source>Transformer Voltage Ratio: To be determined by the factory nameplate, not modifiable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4913"/>
        <source>Reactive Power Output Mode: Default non-adjustable, options include Power Factor, Reactive Power, non-adjustable.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1195"/>
        <location filename="../win.cpp" line="4921"/>
        <source>Converter Anti-Reverse Flow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4922"/>
        <source>Converter Anti-Reverse Flow: Enable, Disable; Enabling prevents converter current from flowing into the grid, while Disabling allows converter current to flow into the grid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4931"/>
        <source>Frequency Deviation Deadzone: A frequency difference settings to prevent unnecessary frequency regulation actions during minor grid frequency fluctuations. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4940"/>
        <source>Active Frequency Regulation Coefficient: The active frequency regulation coefficient can be configured. (Note: This option is generally used in large grid-on power stations.)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4984"/>
        <source>Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5013"/>
        <source>When the dry contact is enabled, the device will perform the selected action when there is a change in the signal.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5014"/>
        <source>Input Dry Contact:                       
Enabled: Triggers the Action when the dry contact detects a state other than the specified NO/NC.                      
Disabled: No action is taken when the dry contact detects a state other than the specified NO/NC.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5023"/>
        <source>DI 1 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5031"/>
        <source>DI 2 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5039"/>
        <source>DI 3 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5047"/>
        <source>DI 4 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5055"/>
        <source>DI 5 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5063"/>
        <source>DI 6 Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5174"/>
        <source>DOD protection: Actions to be performed when DOD protection is triggered. The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5183"/>
        <source>The action performed when the charge ban is triggered;Optional function: NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5192"/>
        <source>The action to be performed when a ban is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5200"/>
        <source>level 1 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5209"/>
        <source>level 2 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5218"/>
        <source>level 3 alarm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5227"/>
        <source>level 1 alarm CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5228"/>
        <source>The charging power executed when a level 1 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5236"/>
        <source>level 2 alarm CP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5237"/>
        <source>The charging power executed when a level 2 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5254"/>
        <source>level 1 alarm DP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5255"/>
        <source>The discharging power executed when a level 1 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5264"/>
        <source>The discharging power executed when a level 2 alarm is triggered.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5680"/>
        <source>Upgrade prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5681"/>
        <source>1. Make sure to press the EPO button before upgrading.                              
2. Before upgrading the DCDC, switch off the ship-type switch of the DCDC module.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5703"/>
        <source>Working mode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5704"/>
        <source>When selecting the manual mode, the converter’s operating status, charging or discharging power (active power), reactive power, power factor etc,can be controlled through HMI or EMS.                              When selecting the UPS mode, When the grid side is abnormal, the system will switch from zero power to grid-off discharge mode to provide energy to critical loads. Please go to the &quot;Battery Settings&quot; page to configure this mode. Note: This mode is only applicable to lithium battery mode and requires normal communication between the converter and BMS.                              Peak shaving and valley filling mode is used for peak-valley price arbitrage. The converter can operate according to the local peak-valley electricity price periods. Please set the operating time period, charging or discharging mode, charging or discharging power, and other information on the &quot;Mixed mode&quot; page.
Grid expansion.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5707"/>
        <source>Click to view grid expansion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3331"/>
        <source>Constant power(AC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3337"/>
        <source>Manual</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3567"/>
        <source>Grid_capacity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3586"/>
        <source>Turn_on_SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3595"/>
        <source>Turn_off_SOC</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3604"/>
        <source>Turn_on_cell_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3613"/>
        <source>Turn_off_cell_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3622"/>
        <source>Turn_on_total_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3631"/>
        <source>Turn_off_total_vol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3640"/>
        <source>UPS_charge_power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3649"/>
        <source>Monthly_cycle_time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3659"/>
        <source>Capacity, the capacity of the lead-acid battery.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3663"/>
        <source>Cell_number_2V</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3669"/>
        <source>This is the floating charge voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3674"/>
        <source>This is the filling voltage.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3724"/>
        <source>Start_Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3725"/>
        <source>End_Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3727"/>
        <source>Power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3728"/>
        <source>9:00</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3729"/>
        <source>10:00</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4471"/>
        <source>This is the monitoring version number.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4724"/>
        <source>Energy meter model: The energy meter model is selected according to the type of energy meter that is connected. According to the characteristics and specifications of the connected watt-hour meter, select the corresponding watt-hour meter model, which can be selected NONE, DTSD1352, AMC96-E4/KC or ADL3000-E-B.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9590"/>
        <location filename="../win.cpp" line="3688"/>
        <source>Generator turn off voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="9654"/>
        <location filename="../win.cpp" line="3693"/>
        <source>Generator turn on voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4479"/>
        <source>Protocol Version</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4480"/>
        <source>This is the protocol version number.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4489"/>
        <source>This is the converter software version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4498"/>
        <source>This is the CPLD software version.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4506"/>
        <source>SN</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4507"/>
        <source>This is SN, the serial number of the product.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8501"/>
        <location filename="../win.cpp" line="4521"/>
        <source>Lithium</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4530"/>
        <source>BMS Comm type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4551"/>
        <source>EMS Comm type</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4570"/>
        <source>Auto</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="554"/>
        <location filename="../win.cpp" line="4570"/>
        <source>BAT protocol</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3496"/>
        <source>Set the charging power limit to allow the maximum power of charging.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3505"/>
        <source>The discharge power limit is set to allow the maximum power of the discharge.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3454"/>
        <source>Charge Vol upper Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3472"/>
        <source>Discharge Vol lower Limit delta</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4692"/>
        <source>English</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4693"/>
        <source>Set the display language of the display screen, which can be selected as Chinese and English. The system will restart when switching languages.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4706"/>
        <source>upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4714"/>
        <source>Allow</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4715"/>
        <source>Set whether the display is enabled sound, which can be allowed(Allow) or prohibited(forbid).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4723"/>
        <source>NONE</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4732"/>
        <source>20</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4732"/>
        <source>Bms Com. Fault Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4733"/>
        <source>BMS communication fault determination time: The BMS communication fault determination time refers to the BMS communication fault when the BMS communication is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4741"/>
        <source>EMS Com. Fault Model</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4742"/>
        <source>EMS communication fault determination time: The EMS communication fault determination time refers to the time when the communication between the EMS is disconnected and the communication is not recovered after a preset period of time.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1051"/>
        <location filename="../win.cpp" line="4785"/>
        <source>Vol protection upper limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1099"/>
        <location filename="../win.cpp" line="4794"/>
        <source>Vol protection lower limit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4803"/>
        <location filename="../win.cpp" line="4812"/>
        <location filename="../win.cpp" line="4821"/>
        <location filename="../win.cpp" line="4831"/>
        <location filename="../win.cpp" line="4840"/>
        <location filename="../win.cpp" line="4849"/>
        <location filename="../win.cpp" line="4858"/>
        <source>prohibit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4885"/>
        <source>Output Fre grade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4894"/>
        <source>Output vol level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4949"/>
        <source>Grid restoration time: reserved function, setting invalid.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4967"/>
        <source>Number of modules for PCS, default 1(invalid setting).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4975"/>
        <source>restore</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4976"/>
        <source>Restore the factory default Settings.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4984"/>
        <source>Backup Set Parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4985"/>
        <source>Backup setting parameters: Backup setting parameters refers to backing up the parameters set on the current device so that the backup parameter Settings can be restored when needed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4993"/>
        <source>Restore Backup Set Parameters</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4993"/>
        <source>Restore
Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="4994"/>
        <source>Restore backup setting parameters: Restore backup setting parameters means to restore the device to the last backup setting parameters and restart the device.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5002"/>
        <source>Clear</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5003"/>
        <source>Clear previous recorded data and operation data of the system.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5012"/>
        <source>Normally closed circuit (NC) or normally open circuit (NO) according to field Settings.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5071"/>
        <source>DI_1_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5079"/>
        <source>DI_2_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5087"/>
        <source>DI_3_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5095"/>
        <source>DI_4_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5103"/>
        <source>DI_5_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5111"/>
        <source>DI_6_NC_O</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5119"/>
        <source>DI_1_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1591"/>
        <location filename="../win.ui" line="1635"/>
        <location filename="../win.ui" line="1679"/>
        <location filename="../win.cpp" line="5127"/>
        <location filename="../win.cpp" line="5135"/>
        <location filename="../win.cpp" line="5143"/>
        <source>Prompt</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5127"/>
        <source>DI_2_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5135"/>
        <source>DI_3_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5143"/>
        <source>DI_4_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5151"/>
        <source>DI_5_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5159"/>
        <source>DI_6_Action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5173"/>
        <location filename="../win.cpp" line="5182"/>
        <location filename="../win.cpp" line="5191"/>
        <location filename="../win.cpp" line="5209"/>
        <source>Standby</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5200"/>
        <source>NO action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5201"/>
        <source>Action to be performed when level 1 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5210"/>
        <source>Action to be performed when level 2 alarm is triggered.The optional functions are NO action, Power down, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5219"/>
        <source>Action that is performed when level 3 alarm is triggered.The optional functions are NO action, Standby, Shut down,0 power standby.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5263"/>
        <source>level 2 alarm DP</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5282"/>
        <source>It is used for internal debugging only.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5313"/>
        <source>Debug variable 1 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5321"/>
        <source>Debug variable 2 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5329"/>
        <source>Debug variable 3 addr</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5337"/>
        <source>Debug memery var 1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5345"/>
        <source>Debug memery var 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5353"/>
        <source>Debug memery var 3</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5361"/>
        <source>Input Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5369"/>
        <source>Input Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5377"/>
        <source>1.5 Voltage revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5385"/>
        <source>Bus Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5393"/>
        <source>Grid A AB Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5401"/>
        <source>Grid B BC Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5409"/>
        <source>Grid C CA Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5417"/>
        <source>Output A Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5425"/>
        <source>Output B Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5433"/>
        <source>Output C Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5441"/>
        <source>INV A Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5449"/>
        <source>INV B Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5457"/>
        <source>INV C Vol revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5465"/>
        <source>INV A ind Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5473"/>
        <source>INV B ind Cur revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5481"/>
        <source>INV_C_ind_Cur_revise</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5577"/>
        <source>static</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5577"/>
        <source>If this parameter is selected, static IP addresses are used.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5600"/>
        <source>This is an automatic IP acquisition, currently not supported.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5600"/>
        <source>dhcp</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5608"/>
        <source>Call in test data (for internal testing personnel only).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5616"/>
        <source>Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="5616"/>
        <source>Click here to modify the time displayed on the HMI.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3393"/>
        <source>Local</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3411"/>
        <source>Parallel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4636"/>
        <location filename="../win.cpp" line="3178"/>
        <source>Maintenance Bypass Breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3196"/>
        <source>Not starting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3205"/>
        <location filename="../win.cpp" line="5119"/>
        <location filename="../win.cpp" line="5151"/>
        <location filename="../win.cpp" line="5159"/>
        <location filename="../win.cpp" line="5218"/>
        <source>Shut down</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="3214"/>
        <source>Reactive Power Regulation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="1569"/>
        <location filename="../win.ui" line="1613"/>
        <location filename="../win.ui" line="1657"/>
        <location filename="../win.cpp" line="3232"/>
        <location filename="../win.cpp" line="5023"/>
        <location filename="../win.cpp" line="5039"/>
        <location filename="../win.cpp" line="5047"/>
        <location filename="../win.cpp" line="5055"/>
        <location filename="../win.cpp" line="5063"/>
        <source>Enable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3926"/>
        <source>PCS voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3936"/>
        <source>PCS voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3946"/>
        <source>PCS voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3956"/>
        <source>PCS current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3966"/>
        <source>PCS current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3976"/>
        <source>PCS current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3986"/>
        <source>PCS Active P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3991"/>
        <source>PCS Reactive P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3996"/>
        <source>PCS Parent P.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="4001"/>
        <source>PCS Pf</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3931"/>
        <location filename="../win.cpp" line="1191"/>
        <location filename="../win.cpp" line="2863"/>
        <source>Battery voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3941"/>
        <location filename="../win.cpp" line="1191"/>
        <location filename="../win.cpp" line="2872"/>
        <source>Battery current</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3951"/>
        <location filename="../win.cpp" line="1191"/>
        <location filename="../win.cpp" line="2881"/>
        <source>Battery power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3961"/>
        <location filename="../win.cpp" line="1192"/>
        <location filename="../win.cpp" line="2890"/>
        <source>Bus voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3971"/>
        <location filename="../win.cpp" line="1192"/>
        <location filename="../win.cpp" line="2899"/>
        <source>IGBT temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="3981"/>
        <location filename="../win.cpp" line="1193"/>
        <location filename="../win.cpp" line="2908"/>
        <source>Environment temperature</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1398"/>
        <source>Converter fault</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1399"/>
        <source>During soft startup of converter, inverter voltage RMS more then 1.2Vgrid or inverter voltage RMS less than 0.3Vgrid after 30s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1400"/>
        <source>PCS shut down and Stop the soft startup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1410"/>
        <source>Battery low voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1410"/>
        <location filename="../win.cpp" line="1422"/>
        <location filename="../win.cpp" line="1482"/>
        <location filename="../win.cpp" line="1494"/>
        <location filename="../win.cpp" line="1506"/>
        <location filename="../win.cpp" line="1566"/>
        <location filename="../win.cpp" line="1578"/>
        <location filename="../win.cpp" line="1590"/>
        <location filename="../win.cpp" line="1602"/>
        <location filename="../win.cpp" line="1614"/>
        <location filename="../win.cpp" line="1638"/>
        <location filename="../win.cpp" line="1674"/>
        <location filename="../win.cpp" line="1686"/>
        <source>Warning</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1411"/>
        <source>The DC input/output voltage is lower than the battery EOD voltage or less than 1.414 times the grid line voltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1412"/>
        <location filename="../win.cpp" line="1460"/>
        <location filename="../win.cpp" line="1472"/>
        <location filename="../win.cpp" line="1496"/>
        <location filename="../win.cpp" line="1508"/>
        <location filename="../win.cpp" line="1520"/>
        <location filename="../win.cpp" line="1532"/>
        <location filename="../win.cpp" line="1544"/>
        <location filename="../win.cpp" line="1556"/>
        <location filename="../win.cpp" line="1568"/>
        <location filename="../win.cpp" line="1580"/>
        <location filename="../win.cpp" line="1592"/>
        <location filename="../win.cpp" line="1604"/>
        <location filename="../win.cpp" line="1616"/>
        <location filename="../win.cpp" line="1628"/>
        <location filename="../win.cpp" line="1640"/>
        <location filename="../win.cpp" line="1652"/>
        <location filename="../win.cpp" line="1664"/>
        <location filename="../win.cpp" line="1688"/>
        <location filename="../win.cpp" line="1700"/>
        <location filename="../win.cpp" line="1712"/>
        <source>PCS shut down and the AC contactor is disconnected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1422"/>
        <source>Low battery power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1423"/>
        <source>The battery voltage is lower than the EOD voltage value (applicable to BMS free battery systems to prevent voltage rebound)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1424"/>
        <source>When the PCS is in discharge state, the machine stops (the charging process is not affected) and the AC contactor is disconnected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1425"/>
        <source>Recoverable, The alarm is cleared when the charging time of PCS is longer than 5 minutes</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1434"/>
        <location filename="../win.cpp" line="1446"/>
        <location filename="../win.cpp" line="1710"/>
        <source>Serious failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1436"/>
        <location filename="../win.cpp" line="1448"/>
        <source>PCS shut down, the AC contactor is disconnected, and the DC circuit breaker is tripped</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1437"/>
        <location filename="../win.cpp" line="1449"/>
        <location filename="../win.cpp" line="1509"/>
        <location filename="../win.cpp" line="1593"/>
        <location filename="../win.cpp" line="1641"/>
        <location filename="../win.cpp" line="1713"/>
        <source>Unrecoverable</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1447"/>
        <source>The DC bus voltage is less than 200V, the DC current is more than 50A, and the judgment time is 200us</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1458"/>
        <source>The output contactor is open</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1459"/>
        <source>When PCS is running, the auxiliary contact signal of AC contactor is in the disconnected state</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1470"/>
        <source>Output contactor short circuit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1471"/>
        <source>When PCS is shut down, the auxiliary contact signal of AC contactor is closed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1482"/>
        <source>The converter is overheated</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1483"/>
        <source>IGBT temperature exceeds 105℃ or reactor temperature exceeds 160℃</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1484"/>
        <source>IGBT overtemperature: derating operation (grid-connected); IGBT overtemperature: PCS shut down (off-grid), AC contactor is disconnected; Reactor overtemperature: PCS shut down and AC contactor is disconnected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1494"/>
        <source>Output over load</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1495"/>
        <source>Off-grid load power &gt;110%Pn</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1506"/>
        <source>The positive and negative terminals of the battery are connected inversely fault</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1507"/>
        <source>The DC input is reversed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1518"/>
        <source>The DC contactor is faulty</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1519"/>
        <source>When the driving signal is a closed signal, the pressure difference between the battery and the bus is greater than 50V;When the driving signal is off, the auxiliary contact signal is closed</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1530"/>
        <source>EMS communicate
fault</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1531"/>
        <source>The communication between PCS and EMS is lost, and the judgment time is 3 minutes</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1533"/>
        <location filename="../win.cpp" line="1545"/>
        <source>Recoverable, the fault recovers automatically 30 seconds after it is rectified</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1542"/>
        <source>BMS communicate
fault</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1543"/>
        <source>Communication loss between PCS and BMS, judgment time 50s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1554"/>
        <source>Converter phase loss fault</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1555"/>
        <source>When the grid-connected power is greater than 50%, one or more lines of the three-phase circuit have no output power, and the judgment time is 10s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1566"/>
        <source>Grid overvoltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1567"/>
        <location filename="../win.cpp" line="1579"/>
        <source>If the power grid voltage exceeds the maximum allowable voltage (90% to 70% can be set), the judgment time is 1s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1578"/>
        <source>Grid undervoltage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1590"/>
        <source>Grid reverse sequence</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1591"/>
        <source>The three-phase phase sequence is reversed (the positive sequence mode value of the grid voltage is less than the negative sequence mode value), and the judgment time is 1s</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1602"/>
        <source>Grid frequency anomaly</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1603"/>
        <source>Grid frequency frequency beyond the allowable range of PCS (±2Hz can be set)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1614"/>
        <source>Converter shutter island protection</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1615"/>
        <source>Initiative shutter island protection mode, the power grid loses power, and the load matches the grid-connected power and phase Angle of the inverter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1626"/>
        <source>Drive line fault</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1627"/>
        <source>The driver cable port is loose</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1638"/>
        <source>Lightning protection fault</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1639"/>
        <source>Surge arrester breakdown or leakage</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1710"/>
        <source>Insulation impedance anomaly</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1650"/>
        <source>The AC auxiliary power supply is faulty</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1651"/>
        <source>The AC auxiliary power output is abnormal. Procedure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1662"/>
        <source>The DC auxiliary power supply is faulty</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1663"/>
        <source>The DC auxiliary power output is abnormal. Procedure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1674"/>
        <source>Fan failure</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1675"/>
        <source>The fan cannot be started</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1676"/>
        <source>PCS derating operation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1686"/>
        <source>Emergency shutdown</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1687"/>
        <source>Press the EPO button on the converter control panel</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1698"/>
        <source>CT or Hall open circuit fault</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1699"/>
        <source>When PCS grid-connected power is greater than 50%, CT detection current is less than 70% of the given quantity</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1711"/>
        <source>For 1000V systems, the positive or negative ground impedance is less than 33KΩ</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1245"/>
        <location filename="../win.cpp" line="2923"/>
        <source>Grid voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1245"/>
        <location filename="../win.cpp" line="2932"/>
        <source>Grid voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1245"/>
        <location filename="../win.cpp" line="2941"/>
        <source>Grid voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1246"/>
        <location filename="../win.cpp" line="2950"/>
        <source>Grid current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1246"/>
        <location filename="../win.cpp" line="2959"/>
        <source>Grid current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1246"/>
        <location filename="../win.cpp" line="2968"/>
        <source>Grid current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1247"/>
        <location filename="../win.cpp" line="2977"/>
        <source>Grid active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1247"/>
        <location filename="../win.cpp" line="2986"/>
        <source>Grid reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1248"/>
        <location filename="../win.cpp" line="2995"/>
        <source>Grid apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1248"/>
        <location filename="../win.cpp" line="3004"/>
        <source>Grid frequency</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1248"/>
        <location filename="../win.cpp" line="3013"/>
        <source>Grid power factor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1291"/>
        <location filename="../win.cpp" line="3028"/>
        <source>Load voltage(AB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1291"/>
        <location filename="../win.cpp" line="3037"/>
        <source>Load voltage(BC)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1291"/>
        <location filename="../win.cpp" line="3046"/>
        <source>Load voltage(CA)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1292"/>
        <location filename="../win.cpp" line="3055"/>
        <source>Load current(A)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1292"/>
        <location filename="../win.cpp" line="3064"/>
        <source>Load current(B)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1292"/>
        <location filename="../win.cpp" line="3073"/>
        <source>Load current(C)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1293"/>
        <location filename="../win.cpp" line="3082"/>
        <source>Load active power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1293"/>
        <location filename="../win.cpp" line="3091"/>
        <source>Load reactive power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1294"/>
        <location filename="../win.cpp" line="3100"/>
        <source>Load apparent power</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1897"/>
        <location filename="../win.cpp" line="1901"/>
        <source>Maintenance Bypass breaker</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1909"/>
        <source>Access control signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1910"/>
        <location filename="../win.cpp" line="3286"/>
        <source>Full power signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1910"/>
        <location filename="../win.cpp" line="3295"/>
        <source>Smoke alarm signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1910"/>
        <source>Hight temp. signal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2280"/>
        <source>This is the interface number, which defaults to eth0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2284"/>
        <source>This is the port number, which defaults to 502 and can be changed as needed.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2288"/>
        <source>This is the IP address. The default is 192.168.1.100.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2292"/>
        <source>This is the subnet mask, 255.255.255.0.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2296"/>
        <source>This is the gateway. The default is 192.168.1.1.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2300"/>
        <source>This is the server IP address. The default is 192.168.1.200.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1065"/>
        <location filename="../win.cpp" line="2352"/>
        <source>Level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1065"/>
        <location filename="../win.cpp" line="2354"/>
        <source>Start Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1065"/>
        <location filename="../win.cpp" line="2356"/>
        <source>End Time</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="8460"/>
        <location filename="../win.cpp" line="1065"/>
        <source>Description</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1103"/>
        <location filename="../win.cpp" line="2574"/>
        <source>ModificationTime</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1103"/>
        <location filename="../win.cpp" line="2576"/>
        <source>RecordEvent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2362"/>
        <source>Power Meter Comm fualttLead-acid abnormal</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="2575"/>
        <source>Time when the system Settings are modified.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.ui" line="5266"/>
        <location filename="../win.ui" line="5290"/>
        <location filename="../win.ui" line="5314"/>
        <location filename="../win.ui" line="5338"/>
        <location filename="../win.ui" line="5362"/>
        <location filename="../win.ui" line="5386"/>
        <location filename="../win.ui" line="5410"/>
        <location filename="../win.ui" line="5434"/>
        <location filename="../win.ui" line="5996"/>
        <location filename="../win.ui" line="6020"/>
        <location filename="../win.ui" line="6044"/>
        <location filename="../win.ui" line="6068"/>
        <location filename="../win.ui" line="6092"/>
        <location filename="../win.ui" line="6116"/>
        <location filename="../win.ui" line="9367"/>
        <location filename="../win.ui" line="9428"/>
        <location filename="../win.ui" line="9498"/>
        <location filename="../win.ui" line="9562"/>
        <location filename="../win.ui" line="9626"/>
        <location filename="../win.cpp" line="2351"/>
        <location filename="../win.cpp" line="3331"/>
        <source>0</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1732"/>
        <source>Change Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../win.cpp" line="1740"/>
        <source>切换语言</source>
        <translation>Change Language</translation>
    </message>
</context>
<context>
    <name>Menu</name>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="14"/>
        <source>Form</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="34"/>
        <source>Host</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="60"/>
        <source>Rt.Data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="86"/>
        <source>Record</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="112"/>
        <source>System</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="143"/>
        <source>Turn on</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="169"/>
        <source>Stand-by</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UI_Menu/Menu.ui" line="195"/>
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
        <source>MainWindow</source>
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
        <location filename="../UpgradeTools/upgradetools.cpp" line="94"/>
        <source>Monitor</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="295"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="682"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="72"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="98"/>
        <source>Backup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="316"/>
        <location filename="../UpgradeTools/upgradetools.ui" line="703"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="76"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="102"/>
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
        <source>MEGA</source>
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
        <location filename="../UpgradeTools/upgradetools.cpp" line="121"/>
        <source>Monitor.hex</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="587"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="125"/>
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
        <location filename="../UpgradeTools/upgradetools.cpp" line="106"/>
        <source>DSP Upgrade</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.ui" line="747"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="112"/>
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
        <location filename="../UpgradeTools/upgradetools.cpp" line="91"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="95"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="99"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="103"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="108"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="113"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="122"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="126"/>
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
        <location filename="../UpgradeTools/upgradetools.cpp" line="95"/>
        <source>After inserting the u disk and checking that there is a Monitor upgrade program &apos;Monitor.hex&apos;, click to upgrade the monitor program.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="73"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="99"/>
        <source>Backup: Click to backup the current program files.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="77"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="103"/>
        <source>Restore: Restore to the most recent backup program files.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="82"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="113"/>
        <source>Click to restart.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="82"/>
        <location filename="../UpgradeTools/upgradetools.cpp" line="113"/>
        <source>Previous Page</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="90"/>
        <source>Baud Rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="91"/>
        <source>Baud Rate: Default is 500k and cannot be modified.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="107"/>
        <source>DSP Upgrade: Insert the u disk and check if there is a DSP upgrade program called &apos;DSPUpdate.hex&apos;. Click to upgrade the DSP.                                
(Note: Press the EPO button before upgrading.))</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="122"/>
        <source>This is the name of the monitoring upgrade program.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../UpgradeTools/upgradetools.cpp" line="126"/>
        <source>This is the DSP upgrade program name.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
