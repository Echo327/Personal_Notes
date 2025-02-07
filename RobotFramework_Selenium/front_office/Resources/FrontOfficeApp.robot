*** Settings ***
Resource    PageObjects/TopNav.robot
Resource    PageObjects/LandingPage.robot
Resource    PageObjects/Team.robot

*** Variables ***

*** Keywords ***
Go To "Landing Page"
    LandingPage.Open "Landing Page"

Check "Landing Page" Loaded
    LandingPage.Confirm Page Loaded

Open "Team"
    TopNav.Click on "Team"
    Team.Confirm Page Loaded

Check "Team" Page Content
    Team.Check Content
