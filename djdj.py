import requests

def check_usda_api():
    # Sample endpoint: search for "apple"
    url = "https://api.nal.usda.gov/fdc/v1/foods/search"
    params = {
        "api_key": "DEMO_KEY",  # replace with your own key from https://fdc.nal.usda.gov/api-key-signup.html
        "query": "apple",
        "pageSize": 1
    }

    try:
        response = requests.get(url, params=params, timeout=10)
        if response.status_code == 200:
            data = response.json()
            if "foods" in data:
                print("USDA API is active and returned data successfully!")
                print(f"Example food item: {data['foods'][0]['description']}")
            else:
                print("Received response, but data structure seems off. Possibly partial service.")
        else:
            print(f"API returned status code {response.status_code}")
    except requests.exceptions.RequestException as e:
        print("🚨 Could not reach USDA API.")
        print(e)

if __name__ == "__main__":
    check_usda_api()
