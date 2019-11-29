## Goal
Your task is to implement a small HTTP service to store objects organized by repository.
Clients of this service should be able to get, put, and delete objects.
The service must follow the requirements in the following section.

## Choose your language

We provide template solutions for Golang and Ruby. Check out the `go` and `ruby` folders. In each folder are some tests that test the API mentioned below. Complete the exercise in **either** language by following the `README.md` in each folder.

**ONLY** keep the `.pid` file that matches the language you chose. For example: if you are doing the exercise in Ruby, remove the `go.pid`.

## Requirements

* Changes must be committed on a branch checked out from `master`.
* The service must de-duplicate data objects by repository.
* The service must listen on port `8282`.
* The service must implement the API as described below.
* The included tests should pass.
* [Submit a pull request for review](https://help.github.com/articles/creating-a-pull-request/) once you are happy with your work.

## Suggestions

* Choose the language you are most familiar with.
* Your code will be read by humans, so organize it sensibly.
* Use this repository to store your work. Committing just the final solution is *ok* but we'd love to see your incremental progress. We suggest taking a look at [GitHub flow](https://guides.github.com/introduction/flow/) to structure your commits.
* You may add more tests in your language if you feel they are appropriate.

## API

### Upload an Object

```
PUT /data/{repository}
```

#### Response

```
Status: 201 Created
{
  "oid": "2845f5a412dbdfacf95193f296dd0f5b2a16920da5a7ffa4c5832f223b03de96",
  "size": 1234
}
```

### Download an Object

```
GET /data/{repository}/{objectID}
```

#### Response

```
Status: 200 OK
{object data}
```

Objects that are not on the server will return a `404 Not Found`.

### Delete an Object

```
DELETE /data/{repository}/{objectID}
```

#### Response

```
Status: 200 OK
```

Deleting objects that do not exist is not an error.
