import os
import requests
from  datetime import datetime




def process_file(file_path):
    result = []
    current_rule_name = None
    with open(file_path, 'r') as file:
        content = file.read()
        lines = content.split('\n')
        for line in lines:
            if line.startswith('# >'):
                current_rule_name = line[4:]
                current_rule_name=current_rule_name.replace(' ', '').replace('/','')
                result.append([current_rule_name])
            elif current_rule_name and line and not line.startswith('#'):
                result[-1].append(line)
    return result






class ParseRules:
    def __init__(self):
        self.parseName='stream.text.list'
        self.saveDir = "./Rules"
        self.links = "links.txt"
        self.baseraw="https://raw.githubusercontent.com/betteryjs/ACL4SSR/refs/heads/master/1stream/Rules/"
        if not os.path.exists(self.saveDir):
            os.makedirs(self.saveDir)
        self.downstream()

    def downstream(self):
        url = "https://raw.githubusercontent.com/1-stream/1stream-public-utils/refs/heads/main/stream.text.list"
        r = requests.get(url)
        with open(self.parseName, 'wb') as f:
            f.write(r.content)

    def process_file(self):
        result = []
        current_rule_name = None
        with open(self.parseName, 'r') as file:
            content = file.read()
            lines = content.split('\n')
            for line in lines:
                if line.startswith('# >'):
                    current_rule_name = line[4:]
                    current_rule_name = current_rule_name.replace(' ', '').replace('/', '').replace('&', '-')
                    result.append([current_rule_name])
                elif current_rule_name and line and not line.startswith('#'):
                    result[-1].append(line)
        return result

    def savetoClashRules(self):

        processed_data = self.process_file()
        baserawbar=open(self.links,'w+')
        for item in processed_data:
            print(item)
            name = item[0]
            data = item[1:]
            filepath=os.path.join(self.saveDir, f"{name}.list")

            text=f"#\t{name}\n"
            text+=f"#\tupdate time {str(datetime.now())}\n\n\n"

            with open(filepath, 'w') as file:
                file.write(text)
            with open(filepath, 'a+') as file:
                file.write('\n'.join(['DOMAIN-SUFFIX,' + c for c in data]))
            baserawbar.write(self.baseraw+f"{name}.list\n")
        baserawbar.close()



if __name__ == '__main__':

    parseRules = ParseRules()
    parseRules.savetoClashRules()