*** Settings ***
Library    SeleniumLibrary

*** Variables ***
${CUSTOMER_HEADER_LABEL}            Our Happy Customers
${ADD_CUSTOMER_LINK_LOCATOR}        id=new-customer
${NEW_CUSTOMER_SUCCESS_LABEL}       Success! New customer added.

*** Keywords ***
Verify Page Loaded
    Wait Until Page Contains    ${CUSTOMER_HEADER_LABEL}

Click Add Customer Link
    Click Link    ${ADD_CUSTOMER_LINK_LOCATOR}

Verify New Customer Added
    Wait Until Page Contains    ${NEW_CUSTOMER_SUCCESS_LABEL}
