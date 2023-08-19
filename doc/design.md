# File parsing state diagram

```mermaid
stateDiagram
    [*] --> frontmatter : ---
    frontmatter --> literature : ---
    literature --> code : +++ &ltidentifier&gt
    code --> literature : +++
    literature --> [*] : EOF
```

