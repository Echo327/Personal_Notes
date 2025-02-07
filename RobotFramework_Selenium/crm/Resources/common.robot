*** Settings ***
Library    SeleniumLibrary

*** Variables ***


*** Keywords ***
Begin Web Test
    # Initialize Selenium
    #Set Selenium Speed      .2s
    Set Selenium Timeout    5s

    Open Browser    about:blank       ${BROWSER}

    # Resize Browser Window
    Set Window Position    0    0
    Set Window Size    1920  1000

End Web Test
    Close All Browsers
