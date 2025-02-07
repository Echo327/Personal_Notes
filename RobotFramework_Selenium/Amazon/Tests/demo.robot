*** Settings ***
Test Setup    Amazon Test Setup
Test Teardown   Amazon Test Teardown

Library    SeleniumLibrary
Resource    ../Resources/Amazon.robot

*** Variables ***
${search term}    weber original 45 cm charcoal grill

*** Test Cases ***
User must sign in to checkout
    [Documentation]  User needs to sign in to checkout
    [Tags]  Amazon

    Log    Opening Amazon Website
    Open Amazon Website

    Log    Searching for ${search term}
    Search For    ${search term}

    Log    Check

    Log    Selecting first product from search results
    Select First Product

    Log    Adding first product to cart
    Add Product to Cart

    Log    Beginning checkout
    Begin Checkout

    Sleep    3

*** Keywords ***
Amazon Test Setup
    Open Browser    about:blank    edge
    Maximize Browser Window
    Set Selenium Timeout    10s

Amazon Test Teardown
    Close Browser
