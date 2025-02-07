*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${URL}          https://automationplayground.com/front-office/
${LANDING_PAGE_HEADER}       Welcome To Our Studio!

*** Keywords ***
Open "Landing Page"
    Go To    ${URL}

Confirm Page Loaded
    Page Should Contain    ${LANDING_PAGE_HEADER}
