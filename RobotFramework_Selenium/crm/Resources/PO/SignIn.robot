*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${SIGNIN_EMAIL_LOCATOR}         id=email-id
${SIGNIN_PASSWORD_LOCATOR}      id=password
${SIGNIN_SUBMIT_BUTTON}         id=submit-id

*** Keywords ***
Sign In
    [Arguments]    ${Email}    ${Password}
    Fill "Email" Field          ${Email}
    Fill "Password" Field       ${Password}
    Click "Submit" Button

Fill "Email" Field
    [Arguments]    ${Email}
    Input Text      ${SIGNIN_EMAIL_LOCATOR}    ${Email}

Fill "Password" Field
    [Arguments]    ${Password}
    Input Text      ${SIGNIN_PASSWORD_LOCATOR}    ${Password}

Click "Submit" Button
    Click Button    ${SIGNIN_SUBMIT_BUTTON}
