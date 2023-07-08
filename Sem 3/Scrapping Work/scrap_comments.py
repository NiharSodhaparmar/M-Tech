from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# Set up Selenium webdriver
driver = webdriver.Chrome('C:\chromedriver')  # Replace with the path to your chromedriver executable

# Open Instagram post URL
post_url = 'https://www.instagram.com/p/Cp2Sq-lv8yG/'  # Replace with the URL of the Instagram post you want to scrape comments from
driver.get(post_url)

# Wait for the comments to load
wait = WebDriverWait(driver, 10)
wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, 'ul.Mr508')))

# Scroll to load all comments (optional, remove if not needed)
while True:
    try:
        driver.execute_script('window.scrollTo(0, document.body.scrollHeight);')
        wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, 'ul.Mr508 > li')))
    except:
        break

# Scrape comments
comment_elements = driver.find_elements(By.CSS_SELECTOR, 'ul.Mr508 > li')
comments = [comment.text for comment in comment_elements]

# Print scraped comments
for comment in comments:
    print(comment)

# Close the webdriver
driver.quit()
