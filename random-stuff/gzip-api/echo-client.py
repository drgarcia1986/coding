import base64
import zlib

from requests import Session
from requests.adapters import HTTPAdapter


class GzipAdapter(HTTPAdapter):
    def add_headers(self, request, **kwargs):
        super().add_headers(request, **kwargs)
        request.headers['Content-Encoding'] = 'gzip'
        request.headers['Content-Length'] = len(request.body)

    def send(self, request, stream=False, **kwargs):
        request.body = zlib.compress(request.body)
        return super().send(request, stream, **kwargs)


class GzipSession(Session):
    def __init__(self):
        super().__init__()
        self.mount('http://', GzipAdapter())
        self.mount('https://', GzipAdapter())


if __name__ == '__main__':
    response = GzipSession().post('http://localhost', json={'my': 'payload'})

    print(response.headers)
    print(response.status_code)
    print(response.json())
