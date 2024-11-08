*** Settings ***
Library    Process
Test Setup    Process Test Setup
Test Teardown    Process Test Teardown

*** Variables ***

*** Test Cases ***
Process Basics
    [Documentation]    Basic test for Process library

    Log   Test
    ${pwd} =    Process.Run Process    python    -c    print('Hey')
    #${pwd} =    Process.Run Process    cmd.exe
    #${OS_run} =    Process.Run Process    robot.exe    -l    .\\Results\\operatingSystem.html    .\\Tests\\operatingSystem.robot
    
    Log    End8675

*** Keywords ***
Process Test Setup
    No Operation

Process Test Teardown
    No Operation
