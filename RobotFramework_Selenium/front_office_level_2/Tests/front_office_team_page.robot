*** Settings ***
Resource            ../Resources/CommonWeb.robot
Suite Setup         CommonWeb.Front Office Suite Setup
Suite Teardown      CommonWeb.Front Office Suite Teardown
Test Setup          Front Office Test Setup

Library             SeleniumLibrary
Resource            ../Resources/FrontOfficeApp.robot

# robot options
# robot.exe -d .\Results\ .\Tests\front_office_team_page.robot
# --reporttitle "Front Office Selenium Course"
# --logtitle "Selelog"
# -c --critical tag (default)
# -n --noncritical tag
# -T --timestampoutputs
# Prefix files with 01__ 02__ .. xx__to change execution order of tests
# --randomize tests|suites|all|none to randomise execution order
# -L --loglevel info|debug|trace|warn|error|none or
# Set Log Level    Debug

*** Variables ***
# Allows changing browser for tests if needed
${BROWSER}      edge

*** Test Cases ***
Check access to "Team" page
    [Documentation]  Checks Team
    [Tags]  Team
    # TODO test
    Log    Assume "Front Office" is open
    FrontOfficeApp.Check "Landing Page" Loaded

    Log    Click on "Team"
    FrontOfficeApp.Open "Team"

Check content of "Team" page
    [Documentation]  Checks Team
    [Tags]  Team

    Log    Assume "Front Office" is open
    FrontOfficeApp.Check "Landing Page" Loaded

    Log    Click on "Team"
    FrontOfficeApp.Open "Team"

    Log    Check "Team" content
    FrontOfficeApp.Check "Team" Page Content

*** Keywords ***
Front Office Test Setup
    Set Log Level    Debug
    FrontOfficeApp.Go To "Landing Page"
