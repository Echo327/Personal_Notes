*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${CONTACT_HEADER_TEXT}         Contact Us
${CONTACT_SUBHEADER_TEXT}      Send Message

*** Keywords ***
Confirm Page Loaded
    Page Should Contain    ${CONTACT_HEADER_TEXT}

Check Content
    Confirm Page Loaded
    Page Should Contain    ${CONTACT_SUBHEADER_TEXT}

