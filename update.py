import requests
import os

OWNER = 'tynnp' 
REPO = 'practice'
TOKEN = os.getenv('UPDATE_PRACTICE')  

def get_file_count():
    url = f'https://api.github.com/repos/{OWNER}/{REPO}/git/trees/main?recursive=1'
    headers = {
        'Authorization': f'token {TOKEN}',
        'Accept': 'application/vnd.github.v3+json'
    }

    response = requests.get(url, headers=headers)
    data = response.json()

    file_count = sum(1 for item in data['tree'] if item['type'] == 'blob')
    return file_count

def update_readme(file_count):
    readme_path = 'README.md'

    with open(readme_path, 'r') as file:
        content = file.readlines()

    found = False
    for i, line in enumerate(content):
        if line.startswith('Số lượng file bài giải:'):
            if content[i].strip() != f'Số lượng file bài giải: {file_count}.':
                content[i] = f'Số lượng file bài giải: {file_count}.\n'
                found = True
            break

    with open(readme_path, 'w') as file:
        file.writelines(content)

    print(f'Updated README.md with file count: {file_count}')

if __name__ == "__main__":
    file_count = get_file_count()
    print(f'File count: {file_count}')  
    update_readme(file_count)
