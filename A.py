# vim test.py
from selenium import webdriver
import time
def get_data(url):
    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    # options.add_argument("disable-gpu")
    driver=webdriver.Chrome(chrome_options=options)
    driver.get(url) 
    # time.sleep(1)
    # iframe = driver.find_element_by_tag_name("iframe")
    # driver.switch_to.frame(iframe)
    # html = driver.page_source

get_data("https://gist.github.com/arsho/47cee8a929a0ff663fe6595e36c0438d")

