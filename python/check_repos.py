import requests
from colorama import init, Fore

def check_repo_exist(repo_name):
    with open('supervis.ini', 'r')as file:
        for line in file:
             if 'owner=' in line:
                 owner_value = line.split('=')[1].strip()
                 break
    url = f"https://api.github.com/repos/{owner_value + "/" +repo_name}"
    response = requests.get(url)

    if response.status_code == 200:
        print(Fore.GREEN + f"Репозиторий {repo_name} существует на GitHub")
    
        # founded repos
        with open('valid_libs.spv', 'a+') as valid:
            valid.write(repo_name+"\n")
    else:
        print(Fore.RED + f"Репозиторий {repo_name} не существует на GitHub")

with open('u_libs.spv', 'r') as file:
    repositories = file.readlines()
    
for repo_name in repositories:
    repo_name = repo_name.strip()  
    check_repo_exist(repo_name)
