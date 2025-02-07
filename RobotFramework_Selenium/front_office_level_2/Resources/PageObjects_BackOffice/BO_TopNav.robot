*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${DASHBOARD_BUTTON}          xpath://*[@id="side-menu"]/li[2]/a
${CHARTS_BUTTON}       xpath://*[@id="side-menu"]/li[3]/a
${FLOT_CHARTS_BUTTON}       xpath://*[@id="side-menu"]/li[3]/ul/li[1]/a

*** Keywords ***
Click on "Dashboard"
    Click Element    ${DASHBOARD_BUTTON}
    Sleep    3

Click on "Flot Charts"
    Click Element    ${CHARTS_BUTTON}
    Click Element    ${FLOT_CHARTS_BUTTON}
    Sleep    3
