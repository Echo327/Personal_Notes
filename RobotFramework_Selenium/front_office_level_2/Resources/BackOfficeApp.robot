*** Settings ***
Resource    PageObjects_BackOffice/BO_TopNav.robot
Resource    PageObjects_BackOffice/BO_LandingPage.robot
Resource    PageObjects_BackOffice/BO_Comments.robot

*** Variables ***

*** Keywords ***
Go To BO "Landing Page"
    BO_LandingPage.Open BO "Landing Page"

Check BO "Landing Page" Loaded
    BO_LandingPage.Confirm BO Page Loaded

Open "Dashboard"
    BO_TopNav.Click on "Dashboard"
    #Team.Confirm Page Loaded

Check "Team" Page Content
    Team.Check Content

Open "Flot Charts"
    BO_TopNav.Click on "Flot Charts"
    #Contact.Confirm Page Loaded

Check "Contact" Page Content
    BO_Contact.Check Content
