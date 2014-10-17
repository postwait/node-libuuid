{
    'targets': [
        {
            'target_name': 'uuid',
            'sources': [ 'src/uuid.cc' ],
            'include_dirs': [
                '<!(node -e "require(\'nan\')")'
            ],
            'conditions': [
                ['OS=="solaris"', {
                    'libraries': [ '-luuid' ],
                    'conditions': [
                        ['target_arch=="ia32"', {
                            'ldflags': [ '-L/opt/omni/lib -R/opt/omni/lib' ]
                        }],
                        ['target_arch=="x64"', {
                            'ldflags': [ '-L/opt/omni/lib/amd64 -R/opt/omni/lib/amd64' ]
                        }]
                    ]
                }],
                ['OS=="linux"', {
                    'libraries': [ '-luuid' ]
                }]
            ]
        }
    ]
}
