*** Settings ***
Library   SeleniumLibrary
Resource    PO/LandingPage.robot
Resource    PO/TopNav.robot

*** Variables ***
${first_result_full_xpath}    /html/body/div[1]/div[1]/div[1]/div[1]/div/span[1]/div[1]/div[4]/div/div/span/div/div/div/div[2]/div/div/div[1]/a

*** Keywords ***
Open ${site_name} Website
    LandingPage.Load    ${site_name}
    LandingPage.Verify Page Loaded    ${site_name}

Search For
    [Arguments]    ${item}
    Input Text    id=twotabsearchtextbox  ${item}
    Click Button    id=nav-search-submit-button
    Wait Until Page Contains    results for "${item}"

Select First Product
    Click Link    xpath=${first_result_full_xpath}
    Wait Until Page Contains    Back to results

Add Product to Cart
    Click Button    id=add-to-cart-button
    Wait Until Page Contains    Added to cart

Begin Checkout
    Click Element    name=proceedToRetailCheckout
    Page Should Contain Element    class:a-spacing-small
    Element Text Should Be    class:a-spacing-small    Sign in
