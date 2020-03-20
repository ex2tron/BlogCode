from jinja2 import Environment, FileSystemLoader


def generate_html(body):
    env = Environment(loader=FileSystemLoader('./scripts/'))
    template = env.get_template('index.html')
    with open('index.html', 'w+') as fout:
        html_content = template.render(data=body)
        fout.write(html_content)


if __name__ == '__main__':
    import json
    with open('./scripts/config.json', 'r') as f:
        data = json.loads(f.read())
    generate_html(data)
