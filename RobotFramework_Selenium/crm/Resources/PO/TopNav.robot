*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${TOPNAV_SIGNIN_LINK}               xpath=//*[@id="SignIn"]
${TOPNAV_SIGNIN_HEADER_LABEL}       Login
${TOPNAV_SIGNOUT_LINK}              Sign Out
${TOPNAV_SIGNOUT_HEADER_LABEL}      Signed Out

*** Keywords ***
Click "Sign In" Link
    Click Link    ${TOPNAV_SIGNIN_LINK}
    Wait Until Page Contains     ${TOPNAV_SIGNIN_HEADER_LABEL}

Click "Sign Out" Link
    Click Link    ${TOPNAV_SIGNOUT_LINK}
    Wait Until Page Contains    ${TOPNAV_SIGNOUT_HEADER_LABEL}
