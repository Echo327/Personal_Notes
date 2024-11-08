*** Settings ***
Library     SeleniumLibrary

*** Variables ***
# Site Name =  Link    Verification Text
@{Amazon}    https://www.amazon.com/    Search Amazon
&{links}
...    Amazon=${Amazon}

*** Keywords ***
Load
    [Arguments]    ${site_name}
    Go To    ${links['${site_name}']}[0]

Verify Page Loaded
    [Arguments]    ${site_name}
    Wait Until Page Contains    ${links['${site_name}']}[1]
