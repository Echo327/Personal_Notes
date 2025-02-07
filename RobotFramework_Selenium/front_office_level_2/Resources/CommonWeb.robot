*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${BROWSER}      edge

*** Keywords ***
Front Office Suite Setup
    Open Browser    about:blank    ${BROWSER}
    # Move test to second monitor
    Set Window Position    0    -1080
    Maximize Browser Window

Front Office Suite Teardown
    Close All Browsers
