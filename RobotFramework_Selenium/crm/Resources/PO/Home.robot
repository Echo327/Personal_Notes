*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${HOME_HEADER_LABEL}        Customers Are Priority One

*** Keywords ***
Navigate To
    Go To    ${TEST_URL}
    Verify Page Loaded

Verify Page Loaded
    Wait Until Page Contains    ${HOME_HEADER_LABEL}
