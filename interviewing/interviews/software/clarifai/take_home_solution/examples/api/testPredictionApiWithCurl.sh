#/bin/bash

# This is client to test API connectivity using cURL

API_KEY=9cdaf16508704c5095a9120767217c99
MODEL_ID=aaa03c23b3724a16a56b629203edc62c
MODEL_VERSION=aa7f35c01e0642fda5cf400f543e7c40

curl -X POST \
    -H "Authorization: Key ${API_KEY}" \
    -H "Content-Type: application/json" \
    -d '
    {
      "inputs": [
        {
          "data": {
            "image": {
              "url": "https://samples.clarifai.com/metro-north.jpg"
            }
          },
          "id": "id1"
        },
        {
          "data": {
            "image": {
              "url": "https://c3.staticflickr.com/9/8622/16491488229_c02862eb1c_o.jpg"
            }
          },
          "id": "id2"
        }
      ]
    }'\
    https://api.clarifai.com/v2/models/$MODEL_ID/versions/$MODEL_VERSION/outputs
