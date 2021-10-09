from flask import Flask, request, jsonify, abort

app = Flask(__name__)
notes = notes = {1 : {'title':'First Note', 'information':'Initial commit :D'}}


@app.route('/', methods=['GET'])
def index():
    return jsonify(notes)


@app.route('/<int:id>', methods=['GET'])
def get_by_id(id):
    if notes.get(id):
        return jsonify(notes.get(id))
    return abort(404)


@app.route('/create', methods=['POST'])
def create():
    new_note_info = request.get_json()
    title = new_note_info.get('title')
    information = new_note_info.get('information')

    note_number = len(notes) + 1
    new_note = {title : information}
    notes[note_number] = new_note
    return jsonify(new_note)


@app.route('/delete/<int:id>', methods=['DELETE'])
def delete(id):
    if notes.get(id):
        notes.pop(id)
        return jsonify(notes)
    
    return abort(500)


@app.route('/update/<int:id>', methods=['PUT'])
def update(id):
    if notes.get(id):
        updated_info = request.get_json()
        title = updated_info.get('title')
        information = updated_info.get('information')

        updated_note = {title : information}
        notes[id] = updated_note
        return jsonify(updated_note)

    return abort(500)



if __name__ == '__main__':
    app.run()