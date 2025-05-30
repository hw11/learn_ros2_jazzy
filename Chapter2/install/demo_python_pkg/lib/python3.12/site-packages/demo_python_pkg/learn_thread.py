import threading
import requests

class DownLoad:
    def download(self, url, callback_world_count):
        print(f'thread: {threading.get_ident()}; start downloading: {url}')
        response = requests.get(url)
        response.encoding = 'utf-8'
        callback_world_count(url, response.text)

    def start_download(self, url, callback_world_count):
        #self.download(url,callback_world_count)
        thread = threading.Thread(target=self.download,args=(url,callback_world_count))
        thread.start()

def world_count(url, result):
    """
    normal function, used for calback
    """
    print(f"{url}:{len(result)}->{result[:5]}")

def main():
    download = DownLoad()
    download.start_download('http://0.0.0.0:8000/novel1.txt',world_count)
    download.start_download('http://0.0.0.0:8000/novel2.txt',world_count)
    download.start_download('http://0.0.0.0:8000/novel3.txt',world_count)