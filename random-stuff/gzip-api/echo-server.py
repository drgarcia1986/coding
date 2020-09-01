from sanic import Sanic
from sanic.response import json

app = Sanic('ECHO')

@app.route('/', methods=['GET', 'POST'])
async def test(request):
    return json({
        'url': request.url,
        'args': request.args,
        'body': request.json,
        'headers': {k: v for k, v in request.headers.items()}
    })

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
