*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${ADD_CUSTOMER_HEADER_LABEL}        Add Customer
${EmailAddress_FIELD_LOCATOR}       id=EmailAddress
${FirstName_FIELD_LOCATOR}          id=FirstName
${LastName_FIELD_LOCATOR}           id=LastName
${City_FIELD_LOCATOR}               id=City
${StateOrRegion_FIELD_LOCATOR}      id=StateOrRegion
${gender_FIELD_LOCATOR}             gender
${SUBMIT_BUTTON_LOCATOR}            Submit

*** Keywords ***
Verify Page Loaded
    Wait Until Page Contains    ${ADD_CUSTOMER_HEADER_LABEL}

Fill New Customer Information
    [Arguments]    ${EmailAddress}    ${FirstName}    ${LastName}
    ...            ${City}    ${StateOrRegion}    ${gender}    ${name}
    Fill "EmailAddress" Field       ${EmailAddress}
    Fill "FirstName" Field          ${FirstName}
    Fill "LastName" Field           ${LastName}
    Fill "City" Field               ${City}
    Fill "StateOrRegion" Field      ${StateOrRegion}
    Fill "gender" Field             ${gender}
    Fill "name" Field               ${name}

Fill "EmailAddress" Field
    [Arguments]    ${EmailAddress}
    Input Text    ${EmailAddress_FIELD_LOCATOR}     ${EmailAddress}

Fill "FirstName" Field
    [Arguments]    ${FirstName}
    Input Text    ${FirstName_FIELD_LOCATOR}        ${FirstName}

Fill "LastName" Field
    [Arguments]    ${LastName}
    Input Text    ${LastName_FIELD_LOCATOR}         ${LastName}

Fill "City" Field
    [Arguments]    ${City}
    Input Text    ${City_FIELD_LOCATOR}             ${City}

Fill "StateOrRegion" Field
    [Arguments]    ${StateOrRegion}
    Select From List By Value    ${StateOrRegion_FIELD_LOCATOR}    ${StateOrRegion}

Fill "gender" Field
    [Arguments]    ${gender}
    Select Radio Button    ${gender_FIELD_LOCATOR}    ${gender}

Fill "name" Field
    [Arguments]    ${name}
    Select Checkbox    name=${name}

Click "Submit" Button
    Click Button    ${SUBMIT_BUTTON_LOCATOR}
