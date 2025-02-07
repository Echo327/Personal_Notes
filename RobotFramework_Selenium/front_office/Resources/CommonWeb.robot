*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${BROWSER}      edge

*** Keywords ***
Front Office Suite Setup
    Open Browser    about:blank    ${BROWSER}
    Maximize Browser Window

Front Office Suite Teardown
    Close All Browsers
