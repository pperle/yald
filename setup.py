from distutils.core import setup, Extension

setup(
    name='yald',
    packages=['yald'],
    version='0.1',
    description="Python extension for calculating the levenshtein distance using C.",
    author='Pascal Perle',
    url='https://github.com/pperle/yald',
    download_url='https://github.com/pperle/yald/archive/0.1.tar.gz',
    classifiers=[
        "License :: OSI Approved :: MIT License",
        "Programming Language :: Python",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: Implementation :: CPython"
    ],
    keywords='string Levenshtein comparison',
    license='MIT',
    include_package_data=True,
    zip_safe=False,
    ext_modules=[
        Extension(
            "yald",
            sources=["./yald/_yald.c", "./yald/levenshtein.c"],
            extra_compile_args=["-O2"]
        )
    ],
    install_requires=['setuptools'],
    entry_points=''
)
