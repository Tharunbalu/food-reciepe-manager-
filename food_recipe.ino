from flask import Flask, request

app = Flask(__name__)

recipes = {
    "Pasta": ["tomato", "cheese", "pasta"],
    "Omelette": ["egg", "salt", "oil"],
    "Salad": ["cucumber", "tomato", "carrot"]
}

@app.route("/", methods=["GET", "POST"])
def home():
    if request.method == "POST":
        user_input = request.form["ingredients"].lower().split(",")
        results = []

        for recipe, items in recipes.items():
            match = len(set(user_input) & set(items))
            if match > 0:
                results.append(recipe)

        return ", ".join(results)

    return "Enter ingredients via POST"

app.run(debug=True)
