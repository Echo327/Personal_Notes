*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${TEAM_BUTTON}          xpath://*[@id="bs-example-navbar-collapse-1"]/ul/li[5]/a
${CONTACT_BUTTON}       xpath://*[@id="bs-example-navbar-collapse-1"]/ul/li[6]/a

*** Keywords ***
Click on "Team"
    Click Element    ${TEAM_BUTTON}
    Sleep    3

Click on "Contact"
    Click Element    ${CONTACT_BUTTON}
    Sleep    3
