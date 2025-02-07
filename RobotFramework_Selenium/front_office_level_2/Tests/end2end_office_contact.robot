*** Settings ***
Resource            ../Resources/CommonWeb.robot
Suite Setup         CommonWeb.Front Office Suite Setup
Suite Teardown      CommonWeb.Front Office Suite Teardown

Library             SeleniumLibrary
Resource            ../Resources/FrontOfficeApp.robot
Resource            ../Resources/BackOfficeApp.robot

# robot options
# robot.exe -d .\Results\ .\Tests\end2end_office_contact.robot

*** Variables ***
# Allows changing browser for tests if needed
${BROWSER}      edge

*** Test Cases ***
Check back office receives "Contact" information from Front Office
    [Documentation]  Checks Contact
    [Tags]  Contact

    Log    Open Front Office
    Front Office Test Setup

    Log    Assume "Front Office" is open
    FrontOfficeApp.Check "Landing Page" Loaded

    Log    Click on "Contact"
    FrontOfficeApp.Open "Contact"

    Log    Check "Contact" content
    FrontOfficeApp.Check "Contact" Page Content

    Log    Fill and Submit Contact Information

    Log    Open Back Office
    Back Office Test Setup

    Log   Check Contact Information was received
    # TODO test because Feature not implemented in course followed
    BackOfficeApp.Open "Flot Charts"
    Sleep    2
    BackOfficeApp.Open "Dashboard"

*** Keywords ***
Front Office Test Setup
    FrontOfficeApp.Go To "Landing Page"

Back Office Test Setup
    BackOfficeApp.Go To BO "Landing Page"
