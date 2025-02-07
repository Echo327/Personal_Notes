*** Settings ***
Resource            ../Resources/CommonWeb.robot
Suite Setup         CommonWeb.Front Office Suite Setup
Suite Teardown      CommonWeb.Front Office Suite Teardown
Test Setup          Front Office Test Setup

Library             SeleniumLibrary
Resource            ../Resources/FrontOfficeApp.robot

*** Variables ***
# Allows changing browser for tests if needed
${BROWSER}      edge

*** Test Cases ***
Check access to "Team" page
    [Documentation]  Checks Team
    [Tags]  Team

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
    FrontOfficeApp.Go To "Landing Page"
