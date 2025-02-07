*** Settings ***
Resource    ./PO/Home.robot
Resource    ./PO/TopNav.robot
Resource    ./PO/SignIn.robot
Resource    ./PO/AddCustomer.robot
Resource    ./PO/Customers.robot

*** Variables ***

*** Keywords ***
Go To "Home" Page
    Home.Navigate To

Login With Credentials
    [Arguments]    ${Email}    ${Password}
    TopNav.Click "Sign In" Link
    SignIn.Sign In    ${Email}    ${Password}
    Customers.Verify Page Loaded

Add Customer
    [Arguments]    ${EmailAddress}    ${FirstName}    ${LastName}
    ...            ${City}    ${StateOrRegion}    ${gender}
    ...            ${name}
    Customers.Click Add Customer Link
    AddCustomer.Verify Page Loaded
    AddCustomer.Fill New Customer Information    ${EmailAddress}    ${FirstName}    ${LastName}
    ...            ${City}    ${StateOrRegion}    ${gender}
    ...            ${name}
    AddCustomer.Click "Submit" Button
    Customers.Verify New Customer Added

Sign Out
    TopNav.Click "Sign Out" Link
