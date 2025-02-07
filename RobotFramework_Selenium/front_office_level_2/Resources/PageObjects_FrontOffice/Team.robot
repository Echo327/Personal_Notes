*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${TEAM_HEADER_TEXT}         Our Amazing Team
${TEAM_SUBHEADER_TEXT}      Lorem ipsum dolor sit amet consectetur.

*** Keywords ***
Confirm Page Loaded
    Page Should Contain    ${TEAM_HEADER_TEXT}

Check Content
    Confirm Page Loaded
    Page Should Contain    ${TEAM_SUBHEADER_TEXT}
