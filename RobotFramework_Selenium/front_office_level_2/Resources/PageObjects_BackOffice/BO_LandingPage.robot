*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${URL_BO}          https://automationplayground.com/back-office/
${LANDING_PAGE_HEADER}       Dashboard

*** Keywords ***
Open BO "Landing Page"
    Go To    ${URL_BO}

Confirm BO Page Loaded
    Page Should Contain    ${LANDING_PAGE_HEADER}
